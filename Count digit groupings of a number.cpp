int dfs(int index,string &s,int last,vector<vector<int>>&dp)
{
    int n=s.size();
    if(index==n)
    {
        return 1;
    }
    if(dp[index][last]!=-1)
    {
        return dp[index][last];
    }
    int sum=0;
    int ans=0;
    for(int i=index;i<n;i++)
    {
        sum+=(s[i]-'0');
        if(sum>=last)
        {
            ans+=dfs(i+1,s,sum,dp);
        }
    }
    return dp[index][last]=ans;
}
class Solution{
	public:
	int TotalCount(string str)
	{
	    int n=str.size();
	    vector<vector<int>>dp(n+10,vector<int>(10*n,-1));
	    return dfs(0,str,0,dp);
	}

};
