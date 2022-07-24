class Solution
{
	public:
    vector <int> bellman_ford(int v, vector<vector<int>> adj, int s) 
    {
        vector<int>distance(v,1e8);
        distance[s]=0;
        int n=adj.size();
        //we have to v-1 relaxations.
        for(int i=0;i<v;i++)
        {
            for(auto x:adj)
            {
                if(distance[x[1]]>(distance[x[0]]+x[2]))
                {
                    distance[x[1]]=distance[x[0]]+x[2];
                }
            }
        }
        return distance;
    }
};
