class Solution
{
public:
    int mod=1000000007;
    #define ll long long
    int bellNumber(int n)
    {
       vector<vector<ll int>>dp(n+1,vector<ll int>(n+1,0));
       for(int i=1;i<=n;i++)
       {
           dp[i][1]=1;
       }
       for(int i=1;i<=n;i++)
       {
           for(int j=2;j<=n;j++)
           {
               dp[j][i]=((i*(dp[j-1][i]))%mod + dp[j-1][i-1])%mod;
           }
       }
       
       long long int ans=0;
       for(int i=1;i<=n;i++)
       {
           ans=(ans+dp[n][i])%mod;
       }
       return ans;
    }
};
