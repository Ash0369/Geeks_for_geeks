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
   
    if(last==-1 || (intervals[index][0]>=intervals[last][1]))
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


//Method-2 : 

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
        
        //dp[i][j] --> Max profit we can get if we start chossing from ith interval
        //and last interval we picked is j-1.
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=-1;j<=i;j++)
            {
                int not_pick=dp[i+1][j+1];
                int pick=0;
                if(j==-1 || intervals[j][1]<=intervals[i][0])
                {
                    pick=intervals[i][2]+dp[i+1][i+1];
                }
                dp[i][j+1]=max(pick,not_pick);
            }
        }
        
        return dp[0][0];
    }
};


//Method-3 : 

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
        
        //dp[i] --> Max profit we can get till ith interval and we are picking ith interval
     
        vector<int>dp(n+1,0);
        dp[0]=intervals[0][2];
        for(int i=1;i<n;i++)
        {
            dp[i]=intervals[i][2];
            int mx=0;
            for(int j=0;j<i;j++)
            {
                if(intervals[j][1]<=intervals[i][0])
                {
                    mx=max(mx,dp[j]);
                }
            }
            dp[i]+=mx;
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};
