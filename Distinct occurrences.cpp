int mod=1e9+7;
class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int n=s.size();
        int m=t.size();
        
        vector<vector<int>>dp(n+10,vector<int>(m+10,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    int a=0;
                    int b=0;
                    if(i>0 && j>0)
                    {
                        a=dp[i-1][j-1];
                    }
                    if(i>0)
                    {
                        b=dp[i-1][j];
                    }
                    dp[i][j]=(a+b)%mod;
                }
                else
                {
                    if(i>0)
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};
