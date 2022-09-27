class Solution
{
public:
    int multiply(int arr[],int i,int j,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return 0;
        }
        int res=INT_MAX;
        if(dp[i][j]==-1)
        {
            for(int k=i;k<j;k++)
            {
                int temp=(arr[i-1]*arr[k]*arr[j])+multiply(arr,i,k,dp)+multiply(arr,k+1,j,dp);
                res=min(res,temp);
            }
            dp[i][j]=res;
        }
        return dp[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return multiply(arr,1,N-1,dp);
    }
};
