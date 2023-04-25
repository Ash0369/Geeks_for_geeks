#define ll long long
const int mod=1e9+7;

map<int,int>mp;
ll int ways(vector<int>&arr,int index,int n,ll int &curr)
{
    if(index==n)
    {
        return curr>2;
    }
    ll int ans2=ways(arr,index+1,n,curr);
    int ele=arr[index];
    if(ele%4==0 || ele%9==0 || ele%25==0)
    {
        return ans2;
    }
    bool res=true;
    ll int temp=curr;
    for(int i=2;i<=ele;i++)
    {
        if(ele%i==0)
        {
            int check=(temp&(1<<i));
            if(check>=1)
            {
                res=false;
                break;
            }
            temp=temp|(1<<i);
            ele=ele/i;
        }
    }
    if(res==false)
    {
        return ans2;
    }
    ll int ans1=(1LL*mp[arr[index]]*ways(arr,index+1,n,temp))%mod;
    return (ans1+ans2)%mod;
}
ll int bpow(int one)
{
    if(one==1)
    {
        return 2;
    }
    if(one==0)
    {
        return 1;
    }
    ll int temp=bpow(one/2);
    
    if(one%2==0)
    {
        return (temp*temp)%mod;
    }
    return (((temp*temp)%mod)*2)%mod;
}
class Solution 
{
public:
    int numberOfGoodSubsets(vector<int>& nums) 
    {
        mp.clear();
        ll int temp=0;
        int n=nums.size();
        vector<int>vec;
        int one=0;
        sort(nums.begin(),nums.end());
        if(nums[0]!=1)
        {
            vec.push_back(nums[0]);
        }
        else
        {
            one++;
        }
        mp[nums[0]]++;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==1)
            {
                one++;
                continue;
            }
            mp[nums[i]]++;
            if(nums[i]!=nums[i-1])
            {
                vec.push_back(nums[i]);
            }
        }
        ll int val=bpow(one);
        return (1LL*val*ways(vec,0,vec.size(),temp))%mod;
    }
};
