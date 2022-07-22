//Method-1 : DFS

class Solution {
  public:

  bool dfs(int node,int parent,vector<int>&visited,vector<int>&dfs_visited,vector<int>adj[])
  {
        dfs_visited[node]=1;
        visited[node]=1;
        for(auto x:adj[node])
        {
            if(!visited[x])
            {
                if(dfs(x,node,visited,dfs_visited,adj))
                {
                    return true;
                }
            }
            else
            {
                if(dfs_visited[x])
                {
                    return true;
                }
            }
        }
        dfs_visited[node]=0;
        return false;
  }

  bool isCyclic(int v, vector<int> adj[]) 
  {
      vector<int>visited(v,0);
      vector<int>dfs_visited(v,0);
      for(int i=0;i<v;i++)
      {
          if(!visited[i])
          {
              if(dfs(i,-1,visited,dfs_visited,adj))
              {
                  return true;
              }
          }
      }
      return false;
  }
};
