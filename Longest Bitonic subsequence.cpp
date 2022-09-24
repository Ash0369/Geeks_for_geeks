class Solution
{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	      int n=nums.size();
        vector<int>dp1(n,1); //dp[i] signify length of longest increasing subsequence which end at i
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    dp1[i]=max(dp1[i],1+dp1[prev]);
                }
            }
        }
        
        vector<int>dp2(n,1); //dp[i] signify length of longest increasing subsequence which end at i
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=n-1;prev>i;prev--)
            {
                if(nums[prev]<nums[i])
                {
                    dp2[i]=max(dp2[i],1+dp2[prev]);
                }
            }
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp1[i]+dp2[i]-1); //-1 as the ith point counted 2 times
        }
        return ans;
	}
};
