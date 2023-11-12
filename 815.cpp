class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target)     {
        int n=routes.size();
        map<int,vector<int>>graph;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                graph[routes[i][j]].push_back(i);
            }
        }
        
        queue<pair<int,int>>q;
        
        q.push({source,0});
        set<int>vis;
        vis.insert(source);
        while(!q.empty())
        {
            int stop=q.front().first;
            int cost=q.front().second;
            q.pop();
            if(stop==target)
            {
                return cost;
            }
            for(auto x:graph[stop])
            {
                for(auto y:routes[x])
                {
                    if(vis.find(y)==vis.end())
                    {
                        q.push({y,cost+1});
                        vis.insert(y);
                    }
                }
                routes[x].clear();
            }
        }
        return -1;
    }
};
