int mod=1000000007;
class Solution{
	public:
		int nthPoint(int n)
		{
		    int dp[n+10];
		    memset(dp,0,sizeof(dp));
		    dp[0]=1;
		    for(int i=0;i<=n-1;i++)
		    {
		        dp[i+1]=(dp[i+1]+dp[i])%mod;
		        dp[i+2]=(dp[i]+dp[i+2])%mod;
		    }
		    return dp[n];
		}
		
};
