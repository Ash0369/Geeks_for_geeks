#define ll long long
int mod=1e9+7;

ll int fact(int x)
{
    ll int ans=1;
    for(int i=1;i<=x;i++)
    {
        ans=(ans*i)%mod;
    }
    return ans;
}
ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        ll int f1=fact(2*n);
        ll int f2=fact(n);
        
        f2=(f2*f2)%mod;
        f2=((n+1)*f2)%mod;
        
        return (f1*inv(f2))%mod;
    }
};
