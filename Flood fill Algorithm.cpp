int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void dfs(int x,int y,vector<vector<int>>& image,vector<vector<int>>&dp,int newc,int ini)
{
    image[x][y]=newc;
    dp[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0&& ny>=0 && nx<n && ny<m && dp[nx][ny]==0 && image[nx][ny]==ini)
        {
            dfs(nx,ny,image,dp,newc,ini);
        }
    }
}
class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int color=image[sr][sc];
        n=image.size();
        m=image[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dfs(sr,sc,image,dp,newColor,color);
        return image;
    }
};
