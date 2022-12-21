#define ll long long
class Solution
{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) 
    {
        vector<int>dp(n+1,0);
        map<ll int,ll int>mp;
        ll int sum=0;
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=dp[i-1]+arr[i];
        }
        for(int i=0;i<=n;i++)
        {
            mp[dp[i]]++;
        }
        ll int ans=0;
        for(auto x:mp)
        {
            ll int temp=x.second;
            ans+=(temp*(temp-1))/2;
        }
        return ans;
    }
};
