int n;
int m;
bool bfs(vector<vector<int>>&graph,int u,vector<bool>&seen,vector<int>&match)
{
    for(int v=0;v<m;v++)
    {
        if(graph[u][v]==1 && seen[v]==false)
        {
            seen[v]=true;
            if(match[v]==-1 || bfs(graph,match[v],seen,match))
            {
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}

int ford(vector<vector<int>>&graph)
{
   
    vector<int>match(m,-1);
    
    int ans=0;
    int v;
    for(int i=0;i<n;i++)
    {
        vector<bool>seen(m,0);
        if(bfs(graph,i,seen,match))
        {
            ans++;
        }
    }
    return ans;
}
class Solution 
{
public:
	int maximumMatch(vector<vector<int>>&G)
	{
	    n=G.size();
        m=G[0].size();
        return ford(G);
	}

};
