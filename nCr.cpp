#define ll long long
int mod=1e9+7;

ll int fact(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    return (n*fact(n-1))%mod;
}

ll int binpow(ll int n,ll int p)
{
    if(p==0)
    {
        return 1;
    }
    ll int a=binpow(n,p/2)%mod;
    a=(a*a)%mod;
    if(p%2==0)
    {
        return a;
    }
    return (a*n)%mod;
}
ll int inv(int n)
{
    ll int x=binpow(n,mod-2);
    return x%mod;
}
class Solution
{
public:
    int nCr(int n, int r)
    {
        if(r>n)
        {
            return 0;
        }
        ll int a=fact(n);
        ll int b=fact(r);
        ll int c=fact(n-r);
        b=(b*c)%mod;
        a=(a*inv(b))%mod;
        
        return a;
    }
};
