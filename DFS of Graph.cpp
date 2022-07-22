class Solution {
  public:
    vector<int> dfsOfGraph(int v, vector<int> adj[]) 
    {
        vector<int>visited(v+1,0);
        vector<int>result;
        visited[0]=1;
        dfs(0,visited,adj,result);
        return result;
    }
    void dfs(int node,vector<int>&visited,vector<int>adj[],vector<int>&result)
    {
        result.push_back(node);
        visited[node]=1;
        for(auto x:adj[node])
        {
            if(!visited[x])
            {
                dfs(x,visited,adj,result);
            }
        }
    }
};
