class Solution
{
    public:
    int lenOfLongSubarr(int nums[],  int N, int K) 
    { 
        int n=N;
        int k=K;
        #define ll long long
        map<ll int,int>mp;
        ll int sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)
            {
                ans=max(ans,i+1);
            }
            ll int need=sum-k;
            if(mp.find(need)!=mp.end())
            {
                ans=max(ans,i-mp[need]);
            }
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
            }
        }
        return ans;
    } 

};
