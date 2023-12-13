#define ll long long
int mod=1000000007;
ll int dp[100005][2];
int n1;
ll int dfs(int index,int last)
{
    if(index==n1)
    {
        return 1;
    }
    if(dp[index][last]!=-1)
    {
        return dp[index][last];
    }
    ll int a=dfs(index+1,0);
    ll int b=0;
    if(last==0)
    {
        b=dfs(index+1,1);
    }
    return dp[index][last]=(a+b)%mod;
}
class Solution
{
public:
	// #define ll long long
	ll countStrings(int n) 
	{
	    n1=n;
	    memset(dp,-1,sizeof(dp));
	    ll int ans=dfs(0,0);
	    return ans;
	}
};
