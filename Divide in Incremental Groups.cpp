//Method-1 : 

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

//Method-2 : 

int dp[105][105];
class Solution 
{
  public:
    int countWaystoDivide(int N, int K) 
    {
        int n=N;
        int k=K;
        memset(dp,0,sizeof(dp));
        if(n<k)
        {
            return 0;
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][1]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                if(i<j)
                {
                    dp[i][j]=dp[i-1][j-1];
                    continue;
                }
               dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
            }
        }
        return dp[n][k];
    }
};
