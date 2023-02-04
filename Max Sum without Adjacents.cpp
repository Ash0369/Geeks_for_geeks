int sum(int index,int *arr,int n,int last,vector<vector<int>>&dp)
{
    if(index==n)
    {
        return 0;
    }
    if(dp[index][last]!=-1)
    {
        return dp[index][last];
    }
    int a=sum(index+1,arr,n,0,dp);
    int b=0;
    if(last==0)
    {
        b=arr[index]+sum(index+1,arr,n,1,dp);
    }
    
    return dp[index][last]=max(a,b);
}
class Solution
{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) 
	{
	    vector<vector<int>>dp(n+1,vector<int>(3,-1));
	    return sum(0,arr,n,0,dp);
	}
};
