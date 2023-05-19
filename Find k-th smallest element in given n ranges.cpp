class Solution
{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries)
    {
        sort(range.begin(),range.end());
        vector<int>distinct;
        int right=range[0][0]-1;
        for(int i=0;i<n;i++)
        {
            
            int end=range[i][1];
            range[i][0]=max(range[i][0],right+1);
            if(end>right)
            {
                distinct.push_back(end-right);
            }
            else
            {
                distinct.push_back(0);
            }
            right=max(right,end);
        }
        vector<int>dp(n,0);
        dp[0]=distinct[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+distinct[i];
        }
        vector<int>ans;
        for(auto x:queries)
        {
            int k=x;
            int ub=lower_bound(dp.begin(),dp.end(),k)-dp.begin();
            if(ub==n)
            {
                ans.push_back(-1);
            }
            else
            {
                int prev=0;
                if(ub-1>=0)
                {
                    prev=dp[ub-1];
                }
                int rem=(k-prev);
                ans.push_back(range[ub][0]+rem-1);
            }
        }
        return ans;
    } 
};
