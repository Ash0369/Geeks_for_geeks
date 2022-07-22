//Method-1:Using BFS

class Solution {
  public:
    bool detect_cycle(int node,vector<int>adj[],vector<int>&visited)
    {
        visited[node]=1;
        queue<pair<int,int>>qu;
        qu.push(make_pair(node,-1));
        while(!qu.empty())
        {
            auto front_node=qu.front();
            for(auto x:adj[front_node.first])
            {
                if(!visited[x])
                {
                    visited[x]=1;
                    qu.push(make_pair(x,front_node.first));
                }
                else
                {
                    if(x!=front_node.second)
                    {
                        return true;
                    }
                }
            }
            qu.pop();
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) 
    {
        vector<int>visited(v+1,0);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                if(detect_cycle(i,adj,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//Method-2:Using DFS Traversal :

class Solution {
  public:
    bool detect_cycle(int node,int parent,vector<int>adj[],vector<int>&visited)
    {
        visited[node]=1;
        for(auto x:adj[node])
        {
            if(!visited[x])
            {
               if(detect_cycle(x,node,adj,visited))
                {
                    return true;
                }
            }
            else
            {
                if(x!=parent)
                {
                    return true;
                }
            }

        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) 
    {
        vector<int>visited(v+1,0);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                if(detect_cycle(i,-1,adj,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
