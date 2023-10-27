int dp[1001][1001];
class Solution{
  public:
    int minimumNumberOfDeletions(string s) 
    {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
            }
        }
        return n-dp[n][n];
    } 
};
