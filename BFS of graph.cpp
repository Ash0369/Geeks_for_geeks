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
