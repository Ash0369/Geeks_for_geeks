int mod=1000000007;
int dp[502][502];
int dfs(int x,int y)
{
    if(x<0 || y<0)
    {
        return 0;
    }
    if(x==0 && y==0)
    {
        return 1;
    }
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    return dp[x][y]=(dfs(x-1,y)+dfs(x,y-1))%mod;
}
class Solution
{
public:
    int ways(int x, int y)
    {
        for(int i=0;i<=x+1;i++)
        {
            for(int j=0;j<=y+1;j++)
            {
                dp[i][j]=-1;
            }
        }
        return dfs(x,y);
    }
};
