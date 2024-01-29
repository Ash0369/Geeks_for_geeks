int mod=1e9+7;
#define ll long long
ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
ll mod_add(ll int a,ll int b){a=a%mod;b=b%mod;return (((a+b)%mod)+mod)% mod;}
ll mod_mul(ll int a,ll int b){a=a%mod;b=b%mod;return (((a*b)% mod)+mod)%mod;}
ll mod_sub(ll int a, ll int b){a=a%mod;b=b%mod;return (((a - b)%mod)+mod)%mod;}
ll mod_div(ll a,ll b){a=a%mod;b=b%mod;return (a*inv(b))%mod;}
class Solution 
{
  public:
    int PossibleStrings(int n, int k) 
    {
        if(k==1)
        {
            return 0;
        }
        ll int ans=1;
        ll int ok=k;
        ll int prev=0;
        ll int offer=26;
        vector<ll int>dp(n+1,0);
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(k>1)
            {
                ans=(ans*26)%mod;
                prev=ans;
                k--;
            }
            else
            {
                ans=(ans*26)%mod;
                ll int sub=0;
                if(j>0)
                {
                    sub=dp[j-1];
                    ll int each=mod_div(sub,26);
                    sub=mod_sub(sub,each);
                    sub=mod_mul(sub,26);
                    ans=mod_sub(ans,sub);
                }
                else
                {
                    ans=mod_sub(ans,26);
                }
                j++;
            }
            dp[i]=ans;
           
        }
        return ans;
    }
};
