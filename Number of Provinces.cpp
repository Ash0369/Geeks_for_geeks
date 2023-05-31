//Method-1 : DFS

void dfs(int index,vector<vector<int>>&adj,vector<int>&dp)
{
    dp[index]=1;
    for(int i=0;i<adj[index].size();i++)
    {
        if(adj[index][i]==1 && dp[i]==0)
        {
            dfs(i,adj,dp);
        }
    }
}
class Solution 
{
  public:
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        vector<int>dp(V+1,0);
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(dp[i]==0)
            {
                dfs(i,adj,dp);
                ans++;
            }
        }
        return ans;
    }
};

