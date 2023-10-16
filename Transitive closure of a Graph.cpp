class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        int n=N;
        for(int k=0;k<n;k++)
        {
            graph[k][k]=1;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int dist=graph[i][k];
                    if(dist>0)
                    {
                        if(graph[k][j]>0)
                        {
                            graph[i][j]=1;
                        }
                    }
                }
            }
        }
        return graph;
    }
};
