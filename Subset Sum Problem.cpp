bool check(vector<int>&arr,int sum,int index,vector<vector<int>>&dp)
{
    if(sum==0)
    {
        return true;
    }
    if(index==0)
    {
        if(arr[0]==sum)
        {
            return true;
        }
        return false;
    }
    if(dp[index][sum]==-1)
    {
        bool pick=check(arr,sum-arr[index],index-1,dp);
        bool not_pick=check(arr,sum,index-1,dp);
    
        dp[index][sum]=pick|not_pick;
    }
    return dp[index][sum];
}
class Solution
{   
public:
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return check(arr,sum,n-1,dp);
    }
};
