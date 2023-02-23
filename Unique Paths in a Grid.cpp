int mod=1e9+7;

int ways(int n,int m,vector<vector<int>> &grid,int x,int y, vector<vector<int>>&dp)
{
    if(x>n ||y>m)
    {
        return 0;
    }
    if(grid[x-1][y-1]==0)
    {
        return 0;
    }
    if(x==n && y==m)
    {
        return 1;
    }
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    int a=ways(n,m,grid,x+1,y,dp);
    int b=ways(n,m,grid,x,y+1,dp);
    
    return dp[x][y]=(a+b)%mod;
    
}
class Solution 
{
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) 
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return ways(n,m,grid,1,1,dp);
    }
};
