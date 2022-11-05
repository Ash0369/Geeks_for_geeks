class Solution 
{
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int v, vector<vector<int>>& edges, int S) 
    {
        vector<int>distance(v,1e8);
        distance[S]=0;
        for(int i=0;i<v;i++)
        {
            for(auto x:edges)
            {
                if(distance[x[0]]+x[2]<distance[x[1]])
                {
                    distance[x[1]]=distance[x[0]]+x[2];
                }
            }
        }
        bool cycle=false;
        //If nth iteration also reduction so -ve cycle
        for(auto x:edges)
        {
            if(distance[x[0]]+x[2]<distance[x[1]])
            {
                cycle=true;
                distance[x[1]]=distance[x[0]]+x[2];
            }
        }
        if(cycle)
        {
            return {-1};
        }
        return distance;
    }
};
