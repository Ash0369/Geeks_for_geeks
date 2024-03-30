#define ll long long
class Solution
{
    public:
    long long ForYou(int n, vector<int> &arr, int m, vector<vector<int>> &order)
    {
        vector<int>dp(n+1,0);
        
        for(auto x:order)
        {
            int l=x[0];
            int r=x[1];
            
            l--;
            r--;
            
            dp[r+1]--;
            dp[l]++;
            
            
        }
        
        sort(arr.begin(),arr.end());
        ll int ans=0;
        ll int mod=1000000007;
        for(int i=1;i<n;i++)
        {
            dp[i]+=dp[i-1];
        }
        sort(dp.begin(),dp.end());
        reverse(dp.begin(),dp.end());
        
        for(auto x:dp)
        {
            if(arr.size()>0)
            {
                ans+=(1LL*x*arr.back());
                ans=ans%mod;
                arr.pop_back();
            }
        }
        return ans;
    }
};
