int mod=1000000007;
class Solution
{
    public:
	int smallSum(vector<int> &arr, int K)
	{
	    int k=K;
	    long long int sum=0;
	    int n=arr.size();
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]<arr[(i+1)%n])
	        {
	            sum=(sum+arr[i])%mod;
	        }
	        else{
	            sum=(sum+(arr[i]%k))%mod;
	        }
	    }
	    return sum;
	}
};
