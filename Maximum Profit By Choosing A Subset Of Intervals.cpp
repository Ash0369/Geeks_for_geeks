//Method-1 : Memoization (Will work only till 130 test cases)

int profit(int index, vector<vector<int>>&intervals,int last,vector<vector<int>>&dp)
{
    if(index==intervals.size())
    {
        return 0;
    }
    if(last!=-1 && dp[index][last]!=-1)
    {
        return dp[index][last];
    }
    int pick=0;
    int not_pick=0;
   
    if(last==-1 || (intervals[index][0]>=intervals[last][1] && intervals[index][0]>intervals[last][0]))
    {
        pick=intervals[index][2]+profit(index+1,intervals,index,dp);
    }
    not_pick=profit(index+1,intervals,last,dp);
    
    if(last==-1)
    {
        return max(pick,not_pick);
    }
    return dp[index][last]=max(pick,not_pick);
}
bool cmp(vector<int>&vec1,vector<int>&vec2)
{
    if(vec1[0]<vec2[0])
    {
        return true;
    }
    return false;
}
class Solution 
{
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) 
    {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return profit(0,intervals,-1,dp);
    }
};
