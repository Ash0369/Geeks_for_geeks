void toposort(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        int v=it.first;
        if(!vis[v])
        {
            toposort(v,adj,vis,st);
        }
    }
    st.push(node);
}
class Solution 
{
  public:
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges)
    {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        int vis[n]={0};
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                toposort(i,adj,vis,st);
            }
        }
        
        //Relaxation of edges
        
        vector<int>dist(n,1e9);
        
        dist[0]=0;//source node
        
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            
            for(auto it:adj[node])
            {
                int v=it.first;
                int wt=it.second;
                
                dist[v]=min(dist[v],wt+dist[node]);//If we give INT_MAX as default then here overflow
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(dist[i]==1e9)
            {
                dist[i]=-1;
            }
        }
        
        return dist;
    }
};
