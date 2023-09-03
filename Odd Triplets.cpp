#define ll long long
class Solution
{
    public:
    long long countTriplet(int N, vector<int> A, int X)
    {
        int n=N;
        vector<int>a=A;
        int x=X;
        
        vector<int>psum(n+5,0);
        vector<int>ssum(n+5,0);
        for(int i=n-1;i>=0;i--)
        {
            ssum[i]=ssum[i+1];
            if(a[i]%2!=0)
            {
                ssum[i]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                psum[i]=psum[i-1];
            }
            if(a[i]%2!=0)
            {
                psum[i]++;
            }
        }
        ll int ans=0;
        
        for(int i=1;i<n-1;i++)
        {
            if(i-x>=0 && i+x<n && a[i]%2!=0)
            {
                ans+=1LL*psum[i-x]*ssum[i+x];
            }
        }
        
        return ans;
    }
};
