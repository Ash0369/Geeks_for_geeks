#define ll long long
ll int dfs(int index,int parent,vector<vector<int>>&tree,string &s,vector<vector<ll int>>&rec,vector<ll int>&f)
{
    vector<ll int>dp(26,0);
    ll int ans=0;
    
    for(auto x:tree[index])
    {
        if(x==parent)continue;
        ans+=dfs(x,index,tree,s,rec,f);
        for(int i=0;i<26;i++)
        {
            ans+=(2LL*dp[i]*rec[x][i]);
            dp[i]+=rec[x][i];
          
        }
    }
    for(int i=0;i<26;i++)
    {
        ll int av=f[i]-dp[i];
        if(i==(s[index]-'a'))
        {
            av--;
        }
        ans+=(2LL*dp[i]*av);
    }
    dp[s[index]-'a']++;
    rec[index]=dp;
    return ans;
}
class Solution 
{
    public:
    long long solve(int N, vector<int> p, string C)
    {
        int n=N;
        vector<vector<int>>tree(n+10);
        for(int i=0;i<N;i++)
        {
            if(p[i]!=-1)
            {
                tree[p[i]].push_back(i);
            }
        }
        vector<ll int>dp(26,0);
        for(auto x:C)
        {
            dp[x-'a']++;
        }
        vector<vector<ll int>>dp2(n+5,vector<ll int>(26,0));
        return dfs(0,-1,tree,C,dp2,dp);
    }
};
