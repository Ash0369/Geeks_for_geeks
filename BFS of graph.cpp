class Solution {
    // Function to return Breadth First Traversal of given graph.
   public:
    vector<int> bfsOfGraph(int v, vector<int> adj[]) 
    {
        vector<int>bfs;
        vector<int>vis(v,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto x:adj[node])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
        return bfs;
    }
};


//If graph has more then 1 components that are not connected then we have to use differennt way : 


class Solution 
{
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) 
    {
        vector<int>visited(v+2);
        vector<int>bfs;
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                queue<int>q;
                q.push(i);
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    bfs.push_back(node);
                    for(auto x:adj[node])
                    {
                        if(!visited[x])
                        {
                            q.push(x);
                            visited[x]=1;
                        }
                    }
                }
            }
        }
        
        return bfs;
    }
};
