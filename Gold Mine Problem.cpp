int dfs(int x,int y,vector<vector<int>>&vec,vector<vector<int>>&dp)
{
    if(x<0 || y<0 || x>=vec.size())
    {
        return 0;
    }
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    int z=vec[x][y];
    int a=dfs(x,y-1,vec,dp);
    int b=dfs(x-1,y-1,vec,dp);
    int c=dfs(x+1,y-1,vec,dp);
    z+=max(a,max(b,c));
    return dp[x][y]=z;
}
class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>>&vec)
    {
        int ans=0;
        vector<vector<int>>dp(n+2,vector<int>(m+2,-1));
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dfs(i,m-1,vec,dp));
        }
        return ans;
    }
};
