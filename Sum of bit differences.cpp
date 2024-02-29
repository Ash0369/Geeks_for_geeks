#define ll long long
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n)
	{
	    ll int ans=0;
	    for(int i=30;i>=0;i--)
	    {
	        int cnt=0;
	        for(int j=0;j<n;j++)
	        {
	            if((arr[j]&(1<<i)))
	            {
	                cnt++;
	            }
	        }
	        int ncnt=n-cnt;
	        
	        ans+=1LL*cnt*ncnt;
	    }
	    return ans*2LL;
	}
};
