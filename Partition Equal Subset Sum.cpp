class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int n=N;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)return 0;
        
        vector<vector<int>>dp(n+2,vector<int>(sum+2,0));
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                dp[i][arr[i]]=1;
                continue;
            }
            for(int j=sum;j>=0;j--)
            {
                if(j-arr[i]>=0)
                {
                    dp[i][j]=dp[i-1][j-arr[i]];
                }
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
        return dp[n-1][sum/2]!=0;
    }
};
