#define ll long long
ll int mod=1e9+7;
ll int pwr(ll int a,ll int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2==0)
    {
        ll int ans1=pwr(a,b/2);
        ll int ans2=(ans1*ans1)%mod;
        return ans2;
    }
    ll int ans1=pwr(a,b/2);
    ll int ans2=(ans1*ans1)%mod;
    ans2=(ans2*a)%mod;
    return ans2;
}
class Solution 
{
  public:
    int totalCount(int n, string s) 
    {
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[0])
            {
                ans=(ans+n-i)%mod;
            }
        }
        return ans;
    }
};
