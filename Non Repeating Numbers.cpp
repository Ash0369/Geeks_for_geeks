class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xr=0;
        for(auto x:nums) xr=xr^x;
        //now form ans
        int ans1=0;
        int ans2=0;
        
        for(int i=0;i<30;i++)
        {
            if((xr&(1<<i))>0)
            {
                //means bit is set
                //In ans1 we will store the xor of all numbers where bit is set
                //In ans2 we will store the xor of all numbers where bit is unset
                //cout<<i<<endl;
                for(auto x:nums)
                {
                    if((x&(1<<i))>0)
                    {
                        ans1=ans1^x;
                    }
                    else
                    {
                        ans2=ans2^x;
                    }
                }
                
                return {min(ans1,ans2),max(ans1,ans2)};
            }
        }
        return {};
        
    }
};
