int dfs(int index,int a,int b,int n,vector<int>&s,int f1,int f2,vector<vector<int>>&dp)
{
    if(index==n)
    {
        return max((f1+a-1)/a,(f2+b-1)/b);
    }
    
    if(dp[index][f1]!=-1)
    {
        return dp[index][f1];
    }
    int ans1=dfs(index+1,a,b,n,s,f1+s[index],f2,dp);
    int ans2=dfs(index+1,a,b,n,s,f1,f2+s[index],dp);
    
    return dp[index][f1]=min(ans1,ans2);
}
class Solution
{
    public:
    int findMinTime(int a, int b, int n, vector<int> &strength)
    {
        int tot=0;
        for(auto x:strength)
        {
            tot+=x;
        }
        vector<vector<int>>dp(n+1,vector<int>(tot+1,-1));
        return dfs(0,a,b,n,strength,0,0,dp);
    }
};
