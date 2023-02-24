#define pii pair<int,int>
class Solution 
{
  public:
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) 
    {
        vector<vector<vector<int>>>graph(n+1);
        for(auto x:edges)
        {
            graph[x[0]].push_back({x[1],x[2],x[3]});
            graph[x[1]].push_back({x[0],x[2],x[3]});
        }
        vector<int>unused(n+1,1e9);
        vector<int>used(n+1,1e9);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,a});
        unused[a]=0;
        while(!pq.empty())
        {
            auto node=pq.top().second;
            pq.pop();
            if(node==b)
            {
                return min(used[b],unused[b]);
            }
            for(auto x:graph[node])
            {
                int possible=x[1]+unused[node];
                if(unused[x[0]]>possible)
                {
                    unused[x[0]]=possible;
                    pq.push({possible,x[0]});
                }
                possible=x[1]+used[node];
                if(used[x[0]]>possible)
                {
                    used[x[0]]=possible;
                    pq.push({possible,x[0]});
                }
                possible=x[2]+unused[node];
                if(used[x[0]]>possible)
                {
                    used[x[0]]=possible;
                    pq.push({possible,x[0]});
                }
            }
        }
        return -1;
    }
};
