
#define ll long long
class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        ll int ans=0;
        ll int last=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>R)
            {
                j=i+1;
                last=0;
                continue;
            }
            else if(a[i]>=L && a[i]<=R)
            {
                last=i-j+1;
                ans+=last;
                continue;
            }
            else if(a[i]<L)
            {
                ans+=last;
            }
            
        }
        return ans;
        
    }
};
