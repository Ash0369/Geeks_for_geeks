class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int vec[], int n)
    {
        vector<int>dp(n+2,0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                dp[i]=vec[i];
            }
            else if(i==1)
            {
                dp[i]=max(vec[i],dp[i-1]);
            }
            else
            {
                dp[i]=max(dp[i-1],vec[i]+dp[i-2]);
            }
        }
        return dp[n-1];
    }
};
