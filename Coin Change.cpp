#define ll long long
ll int ways(int index,int coins[],int n,int sum,vector<vector<ll int>>&dp)
{
    if(sum==0)
    {
        return 1;
    }
    if(sum<0 || index==n)
    {
        return 0;
    }
    if(dp[index][sum]!=-1)
    {
        return dp[index][sum];
    }
    return dp[index][sum]=ways(index,coins,n,sum-coins[index],dp)+ways(index+1,coins,n,sum,dp);
}
class Solution 
{
  public:
    long long int count(int coins[], int N, int sum) 
    {
        
        int n=N;
        vector<vector<ll int>>dp(n+5,vector<ll int>(sum+5,-1));
        return ways(0,coins,n,sum,dp);
        
        
    }
};
