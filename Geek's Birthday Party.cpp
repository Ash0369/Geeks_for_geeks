class Solution 
{
    #define ll long long
  public:
  vector<ll int>party;
  int dfs(int node,int parent,vector<vector<int>>&graph,int n,int depth)
  {
      int ans=0;
      for(auto x:graph[node])
      {
          if(x==parent)
          {
              continue;
          }
          ans+=dfs(x,node,graph,n,depth+1);
      }
      party.push_back(depth-ans);
      return ans+1;
  }
    long long findMaxSnacks(int n, int m, vector<vector<int>> &edges) 
    {
        
        
        vector<vector<int>>graph(n+1);
        vector<int>degree(n+1,0);
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        party.clear();
        dfs(1,-1,graph,n,0);
        sort(party.begin(),party.end());
        reverse(party.begin(),party.end());
        ll int ans=0;
        int i=0;
        while(m--)
        {
            ans+=party[i];
            i++;
        }
        return ans;
    }
};
