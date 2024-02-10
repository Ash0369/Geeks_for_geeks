#define ll long long
ll int dp[101][101][101];
ll int dfs(int x,int y,int n,int k,vector<vector<int>>&arr,ll int c)
{
    if(x==n-1 && y==n-1)
    {
        if(c==k)
        {
            return 1;
        }
        return 0;
    }
    if(c>k)
    {
        return 0;
    }
    if(dp[x][y][c]!=-1)
    {
        return dp[x][y][c];
    }
    ll int ans=0;
    
    //left
    ll int a=0;
    if(x+1<n)
    {
        a=dfs(x+1,y,n,k,arr,c+arr[x+1][y]);
    }
    ll int b=0;
    if(y+1<n)
    {
        b=dfs(x,y+1,n,k,arr,c+arr[x][y+1]);
    }
    
    return dp[x][y][c]=a+b;
}
class Solution 
{
public:
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr)
    {
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,n,k,arr,arr[0][0]);
    }
};
