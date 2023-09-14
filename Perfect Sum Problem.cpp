int mod=1e9+7;
#define ll long long

int n_;
ll int dfs(int index,int sum,int arr[],vector<vector<int>>&dp)
{
    if(index==n_)
    {
        return sum==0;
    }
    if(dp[index][sum]!=-1)
    {
        return dp[index][sum];
    }
    ll int ans=dfs(index+1,sum,arr,dp);
    if(arr[index]<=sum)
    {
        ans=(ans+dfs(index+1,sum-arr[index],arr,dp))%mod;
    }
    return dp[index][sum]=ans;
}

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    n_=n;
	    vector<vector<int>>dp(n+2,vector<int>(sum+2,-1));
        return dfs(0,sum,arr,dp);
	}
	  
};
