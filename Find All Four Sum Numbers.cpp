class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) 
    {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j=i+1;j<n-1;j++)
            {
                if(j!=i+1 && nums[j]==nums[j-1])
                {
                    continue;
                }
                int k=j+1;
                int m=n-1;
                while(k<m)
                {
                    long long int v=1LL*nums[i]+nums[j]+nums[k]+nums[m];
                    if(v==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[m]});
                        k++;
                        m--;
                        while(k<n && nums[k]==nums[k-1])
                        {
                            k++;
                        }
                        while(m>=0 && nums[m]==nums[m+1])
                        {
                            m--;
                        }
                    }
                    else if(v>target)
                    {
                        m--;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};
