ll int dp[100005];
ll int dfs(int index,string &s,int m,int costs[])
{
    if(index>=s.size())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    ll int ans=0;
    if(s[index]=='1')
    {
        return dp[index]=dfs(index+1,s,m,costs);
    }
    else
    {
        ans=1e18;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,costs[i]+dfs(index+i+1,s,m,costs));
        }
    }
    return dp[index]=ans;
}
class Solution
{
    public:
    long long MinCost(string s, int m, int costs[])
    {
        memset(dp,-1,sizeof(dp));
        return dfs(0,s,m,costs);
    }
};
