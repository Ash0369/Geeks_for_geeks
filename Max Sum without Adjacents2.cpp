class Solution
{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) 
	{
	    int dp[100005][5];
	    dp[0][0]=0;
	    dp[0][1]=*arr;
	    
	    for(int i=1;i<n;i++)
	    {
	        arr++;
	        dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
	        
	        dp[i][1]=(*arr)+dp[i-1][0];
	    }
	    return max(dp[n-1][0],dp[n-1][1]);
	}
};
