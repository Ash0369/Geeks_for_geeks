class Solution 
{
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        vector<pair<int,int>>adj[n+1];
        for(auto x:edges)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>parent(n+1,0);
        parent[1]=1;
        vector<int>distance(n+1,INT_MAX);
        
        distance[1]=0;
        
        pq.push({0,1});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int curr=it.first;
            
            for(auto x:adj[node])
            {
                int destnode=x.first;
                int weight=x.second;
                
                if(distance[node]+weight < distance[destnode])
                {
                    distance[destnode]=distance[node]+weight;
                    parent[destnode]=node;
                    pq.push({distance[destnode],destnode});
                }
            }
        }
        if(distance[n]==INT_MAX)
        {
            return {-1};
        }
        vector<int>result;
        
        int node=n;
        while(parent[node]!=node)
        {
            result.push_back(node);
            node=parent[node];
        }
        result.push_back(1);
        reverse(result.begin(),result.end());
        return result;
    }
};
