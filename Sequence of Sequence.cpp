class Solution
{
public:
    int numberSequence(int m, int n)
    {
        vector<vector<int>>dp(n+2,vector<int>(m+10,0));
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                for(int j=1;j<=m;j++)
                {
                    dp[i][j]=1;
                }
                continue;
            }
            else
            {
                for(int j=1;j<=m;j++)
                {
                    for(int k=(2*j);k<=m;k++)
                    {
                        dp[i][k]+=dp[i-1][j];
                    }
                }
            }
        }
        int ans=0;
        
        for(int j=1;j<=m;j++)
        {
            ans+=dp[n-1][j];
        }
        return ans;
    }
};
