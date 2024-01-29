#define ll long long
int mod=1e9+7;
class Solution 
{
  public:
    int MaximumEnergy(int n, vector<int> &e, int k, vector<int> &p) 
    {
        sort(p.begin(),p.end());
        vector<ll int>dp(n+10,0);
        
        int i=0;
        int j=k-1;
        while(i<j)
        {
            dp[p[i]]++;
            dp[p[j]+1]--;
            
            i++;
            j--;
        }
        
        ll int ans=0;
        
        ll int curr=0;
        
        for(int i=0;i<n;i++)
        {
            curr+=dp[i];
            curr=curr%mod;
            ans+=(curr*e[i])%mod;
            ans=ans%mod;
        }
        return ans;
    }
};
