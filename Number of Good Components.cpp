int dfs(int node,vector<vector<int>>&graph,vector<bool>&dp,int sz)
{
    dp[node]=true;
    int cnt=1;
    int res=0;
    for(auto x:graph[node])
    {
        if(dp[x]==true)
        {
            continue;
        }
        int temp=dfs(x,graph,dp,sz);
        if(temp==-1)
        {
            res=-1;
        }
        else
        {
            cnt+=temp;
        }
    }
    if(graph[node].size()==sz && res==0)
    {
        return cnt;
    }
    return -1;
}
class Solution 
{
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) 
    {
        int v=V;
        vector<bool>dp(v+1,false);
        int ans=0;
            
        for(int i=1;i<=v;i++)
        {
            if(dp[i]==false)
            {
                int res=dfs(i,adj,dp,adj[i].size());
                if(res!=-1)
                {
                    if(adj[i].size()==(res-1))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
