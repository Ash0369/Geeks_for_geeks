class Solution
{
    // 1 3 4 7 9 9 12 56
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        #define ll long long
        sort(a.begin(),a.end());
        ll int ans=1e15;
        for(int i=0;i<n;i++)
        {
            if(i+m-1>=n)
            {
                break;
            }
            ans=min(ans,a[i+m-1]-a[i]);
        }
        return ans;
    }   
};
