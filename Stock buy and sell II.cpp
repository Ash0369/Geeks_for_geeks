int dfs(int index,int hold,vector<int>&prices,vector<vector<int>>&dp)
{
    if(index==prices.size())
    {
        return 0;
    }
    if(dp[index][hold]!=-1)
    {
        return dp[index][hold];
    }
    if(hold==1)
    {
        //either sell or not sell
        int ans1=dfs(index+1,hold,prices,dp);
        int ans2=prices[index]+dfs(index+1,0,prices,dp);
        return dp[index][hold]=max(ans1,ans2);
    }
    else
    {
        //either puchase or not purchase
        
        int ans1=dfs(index+1,hold,prices,dp);
        int ans2=dfs(index+1,1,prices,dp)-prices[index];
        return dp[index][hold]=max(ans1,ans2);
    }
}
class Solution 
{
  public:
    int stockBuyAndSell(int n, vector<int> &prices) 
    {
        vector<vector<int>>dp(n+5,vector<int>(2,-1));
        return dfs(0,0,prices,dp);
    }
};
