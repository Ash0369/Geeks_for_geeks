int dp[105][105][105];
int ways(int n,int k,int last)
{
    if(n==0 && k==0)
    {
        return 1;
    }
    if(k==0 || n<=0)
    {
        return 0; 
    }
    if(dp[n][k][last]!=-1)
    {
        return dp[n][k][last];
    }
    int ans=0;
    for(int i=last;i<=n;i++)
    {
        //Take i people in this group
        ans=ans+ways(n-i,k-1,i);
    }
    return dp[n][k][last]=ans;
}
class Solution 
{
  public:
    int countWaystoDivide(int N, int K) 
    {
        memset(dp,-1,sizeof(dp));
        return ways(N,K,1);
    }
};
