class Solution 
{
    public:
    int solve(int N, vector<int> p)
    {
        int n=N;
        int ans=n-1;
        vector<int>deg(n,0);
        for(int i=1;i<n;i++)
        {
            deg[i]++;
            deg[p[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1)
            {
                ans--;
            }
        }
        if(ans<0)
        {
            ans=0;
        }
        return ans;
    }
};
