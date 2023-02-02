#define ll long long
ll int ans=-1;
void dfs(int curr,ll int sum,vector<int>&vis,vector<ll int>&pvis,vector<int>&Edge)
{
    if(vis[curr]==1)
    {
        return;
    }
    pvis[curr]=sum;
    vis[curr]=1;
    int node=Edge[curr];
    if(node==-1)
    {
    }
    else if(pvis[node]!=-1)
    {
        ans=max(ans,pvis[curr]-pvis[node]+node);
    }
    else
    {
        dfs(node,sum+node,vis,pvis,Edge);
    }
    pvis[curr]=-1;
    
}


class Solution
{
  public:
  long long largestSumCycle(int N, vector<int> Edge)
  {
      int n=N;
      ans=-1;
      vector<int>vis(n,0);
      vector<ll int>pvis(n,-1);
      for(int i=0;i<n;i++)
      {
          if(vis[i]==0)
          {
              dfs(i,i,vis,pvis,Edge);
          }
      }
      if(ans==-1)
      {
          return -1;
      }
      return ans;
  }
};
