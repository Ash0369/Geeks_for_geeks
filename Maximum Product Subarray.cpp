#define ll long long
class Solution
{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int>nums, int n) 
	{
        ll int ans=-1e18;
        ll int curr=1;
        for(auto x:nums)
        {
            curr=curr*x;
            ans=max(ans,curr);
            if(curr==0)
            {
                curr=1;
            }
        }
        curr=1;
        for(int i=n-1;i>=0;i--)
        {
            curr=curr*nums[i];
            ans=max(ans,curr);
            if(curr==0)
            {
                curr=1;
            }
        }
        return ans;
	
