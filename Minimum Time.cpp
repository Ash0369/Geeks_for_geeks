class Solution 
{
  public:
  
    int solve(vector<int>&tim,vector<int>&search,int k,int pos, vector<int>&dp)
    {
        if(pos>=tim.size())
        {
            return 0;
        }
        if(dp[pos]!=-1)
        {
            return dp[pos];
        }
        int own=tim[pos]+solve(tim,search,k,pos+1,dp);
        int cheat=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            cheat=min(cheat,search[pos]+solve(tim,search,k,pos+i,dp));
        }
        return dp[pos]=min(own,cheat);
    }
    int minTime(int n, vector<int> &tim, vector<int> &search, int k) 
    {
        vector<int>dp(n+1,-1);
        return solve(tim,search,k,0,dp);
    }
};
