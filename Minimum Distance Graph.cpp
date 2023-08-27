class Solution 
{
    public:
    bool graph(int N, vector<vector<int>> adj)
    {
        int n=N;
        int dp[201][201];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=adj[i][j];
                if(adj[i][j]!=adj[j][i])
                {
                    return false;
                }
            }
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]!=adj[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
