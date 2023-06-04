int dp[1001][1001];
int calc(int x,int y,vector<vector<int>> &grid)
{
    int n=grid.size();
    int m=grid[0].size();
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
     if(x==n-1 && y==m-1)
    {
        return grid[x][y];
    }
    int ans1=-1e9;
    int ans2=-1e9;
    if(x+1<n)
    {
        ans1=calc(x+1,y,grid);
    }
    if(y+1<m)
    {
        ans2=calc(x,y+1,grid);
    }
    return dp[x][y]=grid[x][y]+max(ans1,ans2);
}

int calc1(int x,int y,vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    if(x==n-1 && y==m-1)
    {
        return grid[x][y];
    }
    int ans1=1e9;
    int ans2=1e9;
    if(x+1<n)
    {
        ans1=calc1(x+1,y,grid);
    }
    if(y+1<m)
    {
        ans2=calc1(x,y+1,grid);
    }
    return dp[x][y]=grid[x][y]+min(ans1,ans2);
}

class Solution 
{
  public:
    vector<int> possiblePathSum(int n, int m, vector<vector<int>> &grid, int q, vector<int> &queries) 
    {
        int k=abs(grid[0][0]);
        memset(dp,-1,sizeof(dp));
        int mx=calc(0,0,grid);
        
        memset(dp,-1,sizeof(dp));
        int mn=calc1(0,0,grid);
       // cout<<mx<<" "<<mn<<endl;
        vector<int>ans;
        for(auto x:queries)
        {
            if(x<=mx && x>=mn)
            {
                if((mx-x)%(2*k)==0)
                ans.push_back(1);
                else
                ans.push_back(0);
            }
            else
            {
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};
