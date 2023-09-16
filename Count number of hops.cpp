#define ll long long
int mod=1000000007;
class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<ll int>dp(n+2,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=0;
            if(i-1>=0)
            {
                dp[i]=(dp[i]+dp[i-1])%mod;
            }
            if(i-2>=0)
            {
                dp[i]=(dp[i]+dp[i-2])%mod;
            }
            if(i-3>=0)
            {
                dp[i]=(dp[i]+dp[i-3])%mod;
            }
        }
        return dp[n];
    }
};
