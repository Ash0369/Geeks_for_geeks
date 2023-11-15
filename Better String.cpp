#define ll long long
ll int dfs(string &s)
{
    map<char,int>mp;
    int n=s.size();
    ll int cnt=0;
    vector<ll int>dp(n+5,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=2*dp[i-1];
        char c=s[i-1];
        if(mp.find(c)!=mp.end())
        {
            dp[i]=dp[i]-dp[mp[c]];
        }
        mp[c]=i-1;
    }
    return dp[n];
}
class Solution 
{
  public:
    string betterString(string str1, string str2) 
    {
        
        ll int cnt1=0;
        ll int cnt2=0;
       
        cnt1=dfs(str1);
        cnt2=dfs(str2);
        if(cnt1>=cnt2)
        {
            return str1;
        }
        return str2;
    }
};
