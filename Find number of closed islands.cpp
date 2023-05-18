int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool dfs(int x,int y,vector<vector<int>>&dp,vector<vector<int>>&matrix)
{
    
    dp[x][y]=1;
    bool ans=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[nx][ny]==1 && dp[nx][ny]==0)
        {
            
            ans=ans&dfs(nx,ny,dp,matrix);
        }
    }
    if(x==n-1 || y==m-1 || x==0 || y==0)
    {
        return false;
    }
    return ans;
}
class Solution 
{
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) 
    {
        n=N;
        m=M;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==1 || matrix[i][j]==0)
                {
                    continue;
                }
                if(dfs(i,j,dp,matrix))
                {
                   
                    ans++;
                }
            }
        }
        return ans;
    }
};
