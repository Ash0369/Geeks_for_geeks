int burst(int n,vector<int>&arr,int left,int right,vector<vector<int>>&dp)
{
    if(left>right)
    {
        return 0;
    }
    if(dp[left][right]!=-1)
    {
        return dp[left][right];
    }
    int ans=INT_MIN;
    int a=1;
    int b=1;
    if(left!=0)
    {
        a=arr[left-1];
    }
    if(right!=n-1)
    {
        b=arr[right+1];
    }
    for(int i=left;i<=right;i++)
    {
        int cost=a*b*arr[i];
        cost+=burst(n,arr,left,i-1,dp)+burst(n,arr,i+1,right,dp);
        ans=max(ans,cost);
    }
    return dp[left][right]=ans;
}
class Solution 
{
public:
    int maxCoins(int N, vector<int> &arr) 
    {
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return burst(N,arr,0,N-1,dp);
    }
};
