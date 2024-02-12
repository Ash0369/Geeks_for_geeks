class Solution{
public:
    long long sequence(int n)
    {
        int mod=1e9;
        mod+=7;
        
        #define ll long long
        ll int ans=0;
        ll int start=1;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            ll int mul=1;
            while(j--)
            {
                mul=(mul*start)%mod;
                start++;
            }
            ans=(ans+mul)%mod;
        }
        return ans;
    }
};
