class Solution
{
    public:
    int closest3Sum(int nums[], int N, int x)
    {
        int n=N;
        sort(nums,nums+n);
        int i=0;
        int ans=1e9;
        int d=1e9;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int k=n-1;
            int j=i+1;
            while(j<k)
            {
                if(d>(abs(nums[i]+nums[j]+nums[k]-x)))
                {
                    d=abs(nums[i]+nums[j]+nums[k]-x);
                    ans=nums[i]+nums[j]+nums[k];
                }
                if((nums[i]+nums[j]+nums[k])>=x)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};
