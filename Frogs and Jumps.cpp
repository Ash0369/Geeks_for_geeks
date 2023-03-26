class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) 
    {
        int n=N;
        vector<int>dp(leaves+2,0);
        for(int i=0;i<n;i++)
        {
            int ele=frogs[i];
            if(ele>leaves)
            {
                continue;
            }
            if(dp[ele]==1)
            {
                continue;
            }
            for(int j=ele;j<=leaves;j=j+ele)
            {
                dp[j]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=leaves;i++)
        {
            if(dp[i]==0)
            {
                ans++;
            }
        }
        return ans;
    }
};
