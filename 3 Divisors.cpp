class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        int n=1000000;
        vector<bool>dp(n+2,true);
        dp[0]=false;
        dp[1]=false;
        for(long long int i=2;i*i<=n;i++)
        {
            if(dp[i]==true)
            {
                for(int j=i*i;j<=n;j=j+i)
                {
                    dp[j]=false;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<q;i++)
        {
            int cnt=0;
            long long int x=query[i];
            
            for(long long j=2;j*j<=x;j++)
            {
                if(dp[j]==true)
                {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
