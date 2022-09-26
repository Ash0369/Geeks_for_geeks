class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool safe(bool graph[101][101],int node,int rang,vector<int>&curr,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(graph[node][i]==1 && curr[i]==rang && i!=node)
            {
                return false;
            }
        }
        return true;
    }
    bool color(bool graph[101][101],int node,int n,int m,vector<int>&curr)
    {
        if(node==n)
        {
            return true;
        }
        for(int i=1;i<=m;i++)
        {
            if(safe(graph,node,i,curr,n))
            {
                curr[node]=i;
                if(color(graph,node+1,n,m,curr))
                {
                    return true;
                }
                curr[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) 
    {
        vector<int>curr(n+1,0);
        return color(graph,0,n,m,curr);
    }
};
