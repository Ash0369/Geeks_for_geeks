#define ll long long
const int mod=1e9+7;
ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
int a,b,c,d;
bool check(int cnta,int cntb)
{
    ll int num=(1LL*a*cnta)+(1LL*b*cntb);
    while(num>0)
    {
        int x=num%10;
        if(x!=c && x!=d)
        {
            return false;
        }
        num=num/10;
    }
    return true;
}
ll int fact(int x)
{
    ll int ans=1;
    for(int i=1;i<=x;i++)
    {
        ans=(ans*i)%mod;
    }
    return ans;
}
ll int ncr(int num,int i)
{
    ll int fact1=fact(num);
    ll int fact2=fact(i);
    ll int fact3=fact(num-i);
    
    ll int f=(fact2*fact3)%mod;
    return (fact1*inv(f))%mod;
    
}
class Solution 
{
  public:
    int bestNumbers(int N, int A, int B, int C, int D) 
    {
        int n=N;
        a=A;
        b=B;
        c=C;
        d=D;
        ll int ans=0;
        for(int i=0;i<=n;i++)
        {
            int j=n-i;
            //A is i times and B is j times if it form valid then just coun arrangments
            if(check(i,j))
            {
                ans=(ans+ncr(n,i))%mod;
            }
        }
        return ans;
    }
};
