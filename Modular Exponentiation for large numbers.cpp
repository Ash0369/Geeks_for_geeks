class Solution
{
	public:
	#define ll long long 
	    long long power(long long int x,long long int n,long long int M)
	    {
	        if(n==0)
	        {
	            return 1*1LL;
	        }
	        ll int ans=power(x,n/2,M);
	        ans=(ans*ans)%M;
	        if(n%2==0)
	        {
	            return ans;
	        }
	        else
	        {
	            return (x*ans)%M;
	        }
	    }
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    return power(x,n,M);
		}
};
