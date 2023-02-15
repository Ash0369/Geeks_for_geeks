int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int m;
int n;

void dfs(int x,int y,vector<vector<int>>&heights,vector<vector<bool>>&dp)
{
    dp[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        //height we will check > as we are coming from ocean to ground
        if(nx>=0 && ny>=0 && nx<n && ny<m && heights[nx][ny]>=heights[x][y] && dp[nx][ny]==false)
        {
            dfs(nx,ny,heights,dp);
        }
    }
}

class Solution
{   
public:
    int water_flow(vector<vector<int>> &mat,int N,int M)
    {
        n=N;
        m=M;
        
        int cnt=0;
        vector<vector<bool>>dp1(n,vector<bool>(m,false));
        vector<vector<bool>>dp2(n,vector<bool>(m,false));
        for(int i=0;i<m;i++)
        {
            //From Top
            dfs(0,i,mat,dp1);
        }
        for(int i=0;i<m;i++)
        {
            //From bottom
            dfs(n-1,i,mat,dp2);
        }
        for(int i=0;i<n;i++)
        {
            //From left
            dfs(i,0,mat,dp1);
        }
        for(int i=0;i<n;i++)
        {
            //From right
            dfs(i,m-1,mat,dp2);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp1[i][j]==true && dp2[i][j]==true)
                {
                    cnt++;
                }
            }
        }
        return cnt;
        
        
    }
};
