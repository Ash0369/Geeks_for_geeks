class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>>dp(n+1,vector<int>(total+10,0));
        int mx=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=total;j++)
            {
                int z=(9*cost[i])/10;
                if(j>=cost[i])
                {
                    
                    //purchas
                    dp[i][j]=dp[i+1][j-cost[i]+z]+1;
                   
                }
                dp[i][j]=max(dp[i][j],dp[i+1][j]);
            }
        }
        for(int j=0;j<=total;j++)
        {
            mx=max(mx,dp[0][j]);
        }
        return mx;
        
    }
};
