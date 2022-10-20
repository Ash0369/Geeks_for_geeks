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

//Method-2 : BFS

class Solution {
  public:
    void bfs(int node,vector<int>&indegree,vector<int>&result,queue<int>&q,vector<int>adj[])
    {
        result.push_back(node);
        for(auto x:adj[node])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x);
            }
        }
    }
    bool isCyclic(int v, vector<int> adj[]) 
    {
        //If toposort using bfs or Khan's algorthim contain all elements then no cycle , otherwise cycle because topo sort not generated. 
        vector<int>visited(v,0);
        vector<int>result;
        queue<int>q;
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++)
        {
            for(auto x:adj[i])
            {
                indegree[x]++;
            }
        }
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs(node,indegree,result,q,adj);
        }
        if(result.size()==v)
        {
            return false;
        }
        return true;
    }
};


//Method-2 (Extended) Just keep counter to reduce space


class Solution 
{
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) 
    {
	    vector<int>indegree(v,0);
	    queue<int>q;
	    for(int i=0;i<v;i++)
	    {
	        for(auto x:adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    for(int i=0;i<v;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	            
	        }
	    }
	    int cnt=0;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        cnt++;
	        
	        for(auto x:adj[node])
	        {
	            indegree[x]--;
	            if(indegree[x]==0)
	            {
	                q.push(x);
	            }
	        }
	    }
	    if(cnt==v)
	    {
	        return false;
	    }
	    return true;
    }
};
