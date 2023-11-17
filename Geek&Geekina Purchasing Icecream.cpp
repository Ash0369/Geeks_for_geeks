#define ll long long
class Solution 
{
  public:
    long long findGoodPairs(vector<int> a, int n, int k) 
    {
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]].push_back(i);
        }
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            //I am picking this flavor
            int sz=mp[a[i]].size();
            auto lb=lower_bound(mp[a[i]].begin(),mp[a[i]].end(),i+k)-mp[a[i]].begin();
            int av=sz-lb;
            ans+=av;
        }
        return ans;
    }
};
