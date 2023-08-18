class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        #define ll long long
        int left=0;
        int right=0;
        ll int curr=0;
        
        vector<int>ans;
        
        
        while(right<n)
        {
            curr+=arr[right];
            
            while(curr>s)
            {
                curr-=arr[left];
                left++;
            }
            if(curr==s && left<=right)
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
            right++;
        }
        
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        return ans;
        
    }
};
