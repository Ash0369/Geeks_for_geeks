class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;
        
        for(auto x:nums1)
        {
            mp1[x]++;
        }
        for(auto x:nums2)
        {
            mp2[x]++;
        }
        int ans1=0;
        int ans2=0;
        
        for(auto x:nums1)
        {
            if(mp2[x]>0)
            {
                ans1++;
            }
        }
        
        
        for(auto x:nums2)
        {

            if(mp1[x]>0){

                ans2++;

            }

        }
        
        return {ans1,ans2};


    }
};
