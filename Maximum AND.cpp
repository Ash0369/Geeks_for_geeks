class Solution{
    public:
    int maxAnd(int N, vector<int> A)
    {
        int n=N;
        vector<int>dp(40,0);
        for(int i=0;i<=31;i++)
        {
            for(auto x:A)
            {
                if((x&(1LL<<i)))
                {
                    dp[i]++;
                }
            }
        
        }
        
        int ans=0;
        int life=1;
        for(int i=31;i>=0;i--)
        {
            if(dp[i]==n)
            {
                ans=ans|(1LL<<i);
            }
            else if(dp[i]==n-1 && life>0)
            {
                for(auto x:A)
                {
                    if((x&(1LL<<i))==0)
                    {
                        for(int j=i-1;j>=0;j--)
                        {
                            if((x&(1<<j))==0)
                            {
                                dp[j]++;
                            }
                        }
                        break;
                    }
                }
                ans=ans|(1LL<<i);
                life--;
            }
        }
        return ans;
        
    }
};
