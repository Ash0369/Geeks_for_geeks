ll int dp[505][1005];
ll int dfs(int index,vector<int>&p,vector<int>&f,int av)
{
    int n=p.size();
    if(index==n)
    {
        if(av>=0)
        {
            return 0;
        }
        return 1e18;
    }
    if(av>=(n-index))
    {
        return 0;
    }
    if(dp[index][av+500]!=-1)
    {
        return dp[index][av+500];
    }
    ll int ans1=p[index]+dfs(index+1,p,f,av+f[index]);
    ll int ans2=dfs(index+1,p,f,av-1);
    
    return dp[index][av+500]=min(ans1,ans2);
}
class Solution 
{
  public:
    long long minCost(int n, vector<int> &p, vector<int> &f) 
    {
        memset(dp,-1,sizeof(dp));
        return dfs(0,p,f,0);
    }
};
