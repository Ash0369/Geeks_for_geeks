class Solution{   
public:
    int lengthOfLongestAP(int nums[], int n) 
    {
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
        }
        vector<vector<int>>dp(n+5,vector<int>(3*mx,1));
        int ans=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff=nums[j]-nums[i]+mx;
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};
