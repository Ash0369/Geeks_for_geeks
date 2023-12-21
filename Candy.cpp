#define ll long long
class Solution 
{
  public:
    int minCandy(int n, vector<int> &ratings) 
    {
        
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                dp[i]=dp[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                dp[i]=max(dp[i],dp[i+1]+1);
            }
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
