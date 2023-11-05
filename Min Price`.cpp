#define ll long long
ll int dp[505][505];
ll int dfs(int index,int item, vector<int> &p, vector<int> &f)
{
    int z=p.size();
    item=min(item,z);
    if(index==z)
    {
        if(item>=z)
        {
            return 0;
        }
        return 1e15;
    }
    if(dp[index][item]!=-1)
    {
        return dp[index][item];
    }
    ll int c1=dfs(index+1,item,p,f);
    ll int c2=p[index]+dfs(index+1,item+f[index]+1,p,f);
    return dp[index][item]=min(c1,c2);
}
class Solution {
  public:
    long long minCost(int n, vector<int> &p, vector<int> &f) 
    {
        int z=p.size();
        for(int i=0;i<=n+2;i++)
        {
            for(int j=0;j<=n+2;j++)
            {
                dp[i][j]=-1;
            }
        }
        return dfs(0,0,p,f);
    }
};
