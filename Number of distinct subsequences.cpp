#define ll long long
#define mod 1000000007
class Solution 
{
public:
    int distinctSubsequences(string s)
    {
        int n=s.size();
        map<char,ll int>mp;
        vector<ll int>dp(n+1,0);
        dp[0]=2;
        mp[s[0]]=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=(2LL*dp[i-1])%mod;
            
            if(mp.find(s[i])!=mp.end())
            {
                int index=mp[s[i]];
                if(index!=0)
                {
                    dp[i]=(dp[i]-dp[index-1]+mod)%mod;
                }
                else
                {
                    dp[i]=(dp[i]-1+mod)%mod;
                }
            }
            
            mp[s[i]]=i;
        }
        return (dp[n-1]+mod)%mod;
    }
};
