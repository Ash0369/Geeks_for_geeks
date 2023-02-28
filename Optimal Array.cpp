#define ll long long
class Solution
{
public:
    vector<int> optimalArray(int n,vector<int> &a)
    {
        ll int sum=0;
        ll int prev=0;
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<n;i++)
        {
            ll int prev=ans[i-1]+a[i]-a[i/2];
            ans.push_back(prev);
        }
        return ans;
    }
};
