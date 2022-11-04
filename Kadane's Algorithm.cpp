class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        #define ll long long
        
        ll int ans=arr[0];
        
        ll int curr=0;
        
        for(int i=0;i<n;i++)
        {
            ll int x=arr[i];
            curr+=x;
            if(ans<curr)
            {
                ans=curr;
            }
            if(curr<0)
            {
                curr=0;
            }
        }
        return ans;
    }
        
    
};
