int mod=1e9+7;
class Solution
{
	public:
	int TotalWays(int n)
	{
	    long long int dp[n+10][2];
	    memset(dp,0,sizeof(dp));
	    
	    dp[0][0]=1;
	    dp[0][1]=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
	        dp[i][1]=(dp[i-1][0])%mod;
	    }
	    int tot=(dp[n-1][0]+dp[n-1][1])%mod;
	    return (1LL*tot*tot)%mod;
	}
};
