int mod=1000000007;
int dp[1000000];
int f(int n)
{
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        if(n==0)
        {
            return 2;
        }
        if(n==1)
        {
            return 5;
        }
        if(n==2)
        {
            return 9;
        }
        if(n==3)
        {
            return 7;
        }
        
        if(n%2==0)
        {
            return dp[n]=((1LL*f(n-2)*(n-2))+(1LL*f(n-4)*(n-4)))%mod;
        }
       
        return dp[n]=((1LL*f(n-1)*(n-1))+(1LL*f(n-3)*(n-3)))%mod;
}
class Solution 
{
  public:
    int findFun(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};
