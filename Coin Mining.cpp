int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int dfs(int x,int y,int n,vector<vector<int>>&grid)
{
    int ans=0;
    int b=grid[x][y];
    grid[x][y]=0;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]>0)
        {
            ans=max(ans,dfs(nx,ny,n,grid));
        }
    }
    grid[x][y]=b;
    return ans+b;
}
class Solution 
{
  public:
    int maximumCoins(int n, vector<vector<int>> &grid) 
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i+j)%2 && grid[i][j]>0)
                {
                    ans=max(ans,dfs(i,j,n,grid));
                }
            }
        }
        return ans;
    }
};
