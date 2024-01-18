class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<int>dp(n+2,-1);
        for(int i=0;i<n;i++)
        {
            if(gallery[i]!=-1)
            {
                int left=max(0,i-gallery[i]);
                int right=min(n-1,i+gallery[i]);
                
                for(int j=left;j<=right;j++)
                {
                    dp[j]=max(dp[j],right);
                }
            }
        }
        
        int ans=0;
        
        int curr_end=-1;
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]==-1)
            {
                return -1;
            }
            
            if(i>curr_end)
            {
                ans++;
                curr_end=dp[i];
            }
        }
        
        return ans;
    }
};
