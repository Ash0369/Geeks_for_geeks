#define ll long long
ll int dfs(int curr,int sign,vector<vector<int>>&graph,vector<int>&a)
{
    ll int sum=-1e15;
    for(auto x:graph[curr])
    {
        sum=max(sum,dfs(x,sign*(-1),graph,a));
    }
    if(sum==-1e15)
    {
        sum=0;
    }
    return 1LL*sign*a[curr-1]+sum;
}
class Solution 
{
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) 
    {
        vector<vector<int>>graph(N+1);
        for(int i=1;i<=N;i++)
        {
            if(P[i-1]==-1)
            {
                continue;
            }
            graph[P[i-1]].push_back(i);
        }
        ll int ans=-1e15;
        for(int i=1;i<=N;i++)
        {
            ans=max(ans,dfs(i,1,graph,A));
        }
        return ans;
    }
};
