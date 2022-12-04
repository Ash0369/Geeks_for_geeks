int timer=0;
void dfs(int node,int parent,vector<int>&tin, vector<int>&low,vector<int>&mark,vector<int>&vis, vector<int>adj[])
{
    vis[node]=1;
    tin[node]=timer;
    low[node]=timer;
    timer++;
    int child=0;
    for(auto it:adj[node])
    {
        if(it==parent)
        {
            continue;
        }
        if(!vis[it])
        {
            child++; //We will count inside unvisited , so if children are connected internally that count once
            dfs(it,node,tin,low,mark,vis,adj);
            low[node]=min(low[node],low[it]);
            
            if(low[it]>=tin[node] && parent!=-1)
            {
                mark[node]=1;
            }
        }
        else
        {
            low[node]=min(low[node],tin[it]);
        }
    }
    
    if(parent==-1 && child>1)
    {
        mark[node]=1;
    }
}
class Solution 
{
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) 
    {
        vector<int>tin(n);
        vector<int>low(n);
        vector<int>mark(n,0);
        vector<int>vis(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,tin,low,mark,vis,adj);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(mark[i]==1)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
        {
            return {-1};
        }
        return ans;
        
        
    }
};
