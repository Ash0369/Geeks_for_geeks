int n;
int m;
bool bfs(vector<vector<int>>&res,int s,int t,vector<int>&parent)
{
    vector<bool>vis(n+1,false);
    queue<int>q;
    q.push(s);
    parent[s]=-1;
    vis[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false && res[u][i]>0)
            {
                if(i==t)
                {
                    parent[t]=u;
                    return true;
                }
                q.push(i);
                parent[i]=u;
                vis[i]=true;
            }
        }
    }
    return false;
    
}

int ford_ful(vector<vector<int>>&graph,int s,int t)
{
    vector<vector<int>>res(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            res[i][j]=graph[i][j];
            res[j][i]=graph[j][i];
        }
    }
    
    vector<int>parent(n+1,0);
    
    int ans=0;
    int v;
    while(bfs(res,s,t,parent))
    {
        int path_flow=INT_MAX;
        for(v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            path_flow=min(path_flow,res[u][v]);
        }
        
        for(v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            res[u][v]-=path_flow;
            res[v][u]-=path_flow;
        }
        ans+=path_flow;
    }
    return ans;
}
class Solution
{
public:
    int findMaxFlow(int N,int M,vector<vector<int>> Edges)
    {
        n=N;
        m=M;
        vector<vector<int>>graph(n+1,vector<int>(n+1,0));
        for(auto x:Edges)
        {
            //graph[min(x[0],x[1])][max(x[0],x[1])]=x[2];
            graph[x[1]][x[0]]+=x[2];
            graph[x[0]][x[1]]+=x[2];
        }
        return ford_ful(graph,1,n);
    }
};
