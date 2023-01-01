#define ll long long
//https://www.toppr.com/ask/question/the-value-of-the-sum-left-n/
const ll mod = 1e9 + 7;


long long inv(long long int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
ll fact(int n)
{
    ll a=1;
    for(int i=1;i<=n;i++)
    {
        a=(a*i)%mod;
    }
    return a;
}

class Solution
{
	public:
	int compute_value(int n)
	{
	    ll int a=fact(n)%mod;
	    ll int b=fact(2*n)%mod;
	    ll int inva=inv(a);
	    inva=(inva*inva)%mod;
	    return (b*inva)%mod;
	}
};
