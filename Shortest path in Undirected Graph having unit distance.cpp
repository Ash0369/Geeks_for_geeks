class Solution 
{
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src)
    {
        vector<int>vec[n];
        for(int i=0;i<edges.size();i++)
        {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        
        queue<pair<int,int>>q;
        
        q.push({src,0});
        
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int d=node.second;
            int new_d=d+1;
            for(auto x:vec[node.first])
            {
                if(distance[x]>new_d)
                {
                    q.push({x,new_d});
                    distance[x]=new_d;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(distance[i]==INT_MAX)
            {
                distance[i]=-1;
            }
        }
        return distance;
    }
};
