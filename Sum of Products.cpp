class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        #define ll long long
        vector<int>dp(30,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=28;j++)
            {
                if((arr[i]&(1<<j)))
                {
                    dp[j]++;
                }
            }
        }
        
        ll int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=28;j++)
            {
                if((arr[i]&(1<<j)))
                {
                    ans+=1LL*(dp[j]-1)*(1<<j);
                }
            }
        }
        return ans/2;
        
        
    }
};
