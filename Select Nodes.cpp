void dfs(int node,int parent,vector<vector<int>>&graph,vector<vector<int>>&dp)
{
    dp[node][0]=0;
    dp[node][1]=1;
    for(auto x:graph[node])
    {
        if(x==parent)
        {
            continue;
        }
        dfs(x,node,graph,dp);
        dp[node][0]+=dp[x][1];
        dp[node][1]+=min(dp[x][1],dp[x][0]);
    }
   
}
class Solution
{
  public:
    int countVertex(int N, vector<vector<int>>edges)
    {
        int n=N;
        vector<vector<int>>graph(n+1);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dfs(1,-1,graph,dp);
        return min(dp[1][0],dp[1][1]);
    }
};
