#define ll long long
ll int dfs(int index,int parent,vector<vector<int>>&tree,vector<ll int>&dp)
{
    ll int tot=0;
    vector<ll int>keep;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        ll int a=dfs(x,index,tree,dp);
        keep.push_back(a);
        tot+=a;
    }
    ll int otot=tot;
    for(auto x:keep)
    {
        dp[index]+=(1LL*x*(tot-x));
        tot=tot-x;
        dp[index]+=x;
    }
    dp[index]++;
    return otot+1;
}
class Solution 
{
    public:
	
	vector<long long>calcPairs(int n, vector<int> p)
	{
	    vector<vector<int>>tree(n+2);
	    for(int i=1;i<n;i++)
	    {
	        tree[i].push_back(p[i]);
	        tree[p[i]].push_back(i);
	    }
	    vector<ll int>dp(n,0);
	    dfs(0,-1,tree,dp);
	    return dp;
	}
};
