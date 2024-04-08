#define ll long long
ll int dp[1009][1009];
ll int dfs(int i,int j,int n,int arr[])
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=1e15)
    {
        return dp[i][j];
    }
    ll int ans=arr[i]+min(dfs(i+2,j,n,arr),dfs(i+1,j-1,n,arr));
    ll int ans1=arr[j]+min(dfs(i,j-2,n,arr),dfs(i+1,j-1,n,arr));
    
    return dp[i][j]=max(ans,ans1);
}
class Solution
{
    public:
    long long maximumAmount(int n, int arr[])
    {
        for(int i=0;i<n+2;i++)
        {
            for(int j=0;j<n+2;j++)
            {
                dp[i][j]=1e15;
            }
        }
        return dfs(0,n-1,n,arr);
    }
};
