#define ll long long
int mod=1000000007;
class Solution 
{
public:
    int maxSum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        for(int p=30;p>=0;p--)
        {
            queue<int>q;
            for(int i=0;i<n;i++)
            {
                if((nums[i]&(1<<p))>0)
                {
                    q.push(i);
                }
                else
                {
                    if(q.size()>0)
                    {
                        nums[i]=nums[i]|(1<<p);
                        int ele=q.front();
                        nums[ele]=nums[ele]^(1<<p);
                        q.pop();
                        q.push(i);
                    }
                }
            }
        }
        int ans=0;
        int j=n-1;
        while(k--)
        {
            ans=(ans+((1LL*nums[j]*nums[j])%mod))%mod;
            j--;
        }
        return ans;
    }
};
