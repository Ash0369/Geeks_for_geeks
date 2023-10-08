class Solution 
{
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        
        int dp[n+10][m+10];
        
        memset(dp,0,sizeof(dp));
        dp[0][0]=nums1[0]*nums2[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],nums1[i]*nums2[0]);
        }
        for(int i=1;i<m;i++)
        {
            dp[0][i]=max(dp[0][i-1],nums2[i]*nums1[0]);
        }
        int ans=dp[0][0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                int a=nums1[i]*nums2[j];
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a);
                dp[i][j]=max(dp[i][j],a);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
