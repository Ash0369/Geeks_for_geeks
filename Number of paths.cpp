ll int inv(ll int r)
{
	if(r==1) return 1;
	return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
}
class Solution
{
    public:
    long long  numberOfPaths(int M, int N)
    {
        int m=M;
        int n=N;
        
       
        
        ll int num=1;
        ll int den1=1;
        for(int i=0;i<min(m-1,n-1);i++)
        {
            num=(num*(m+n-2-i))%mod;
            den1=den1*(i+1)%mod;
        }
        
        ll int ans=(num*inv(den1))%mod;
        return ans;
    }
};
