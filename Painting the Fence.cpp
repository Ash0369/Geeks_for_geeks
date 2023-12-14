#define ll long long
int mod=1000000007;
class Solution
{
    public:
    long long countWays(int n, int k)
    {
       vector<vector<ll int>>dp(n+2,vector<ll int>(3,0));
       dp[1][0]=k;
       dp[1][1]=0;
       
       for(int i=2;i<=n;i++)
       {
           dp[i][0]=((dp[i-1][0]+dp[i-1][1])*(k-1))%mod;
           dp[i][1]=dp[i-1][0];
       }
       return (dp[n][0]+dp[n][1])%mod;
    }
};
