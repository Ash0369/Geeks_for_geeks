int coin(int left,int right,vector<int>&a,vector<vector<int>>&dp)
{
    if(left>right)
    {
        return 0;
    }
    if(dp[left][right]!=-1)
    {
        return dp[left][right];
    }
    int ans=0;
    int l=1;
    int r=1;
    if(left!=0)
    {
        l=a[left-1];
    }
    if(right!=a.size()-1)
    {
        r=a[right+1];
    }
    for(int i=left;i<=right;i++)
    {
        int cost=l*r*a[i];
        cost+=coin(left,i-1,a,dp)+coin(i+1,right,a,dp);
        ans=max(ans,cost);
    }
    return dp[left][right]=ans;
}
class Solution
{
    public:
    int maxCoins(int N, vector <int> &a)
    {
        int n=N;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return coin(0,n-1,a,dp);
    }
};
