
#define ll long long
class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	ll int ans=0;
    	for(int i=0;i<=31;i++)
    	{
    	    int one=0;
    	    for(int j=0;j<n;j++)
    	    {
    	        if((arr[j]&(1LL<<i)))
    	        {
    	            one++;
    	        }
    	    }
    	    ans+=(1LL*one*(n-one)*(1LL<<i));
    	}
    	return ans;
    }
};
