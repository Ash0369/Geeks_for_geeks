class Solution 
{
  public:
    long long countPairs(int n, int arr[], int k) 
    {
        #define ll long long
        map<int,int>mp;
        ll int cnt=0;
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]%k]++;
        }
        
        for(auto x:mp)
        {
            ll int cnt=x.second;
            ans+=cnt*(cnt-1)/2;
        }
        
        return ans;
    }
};
