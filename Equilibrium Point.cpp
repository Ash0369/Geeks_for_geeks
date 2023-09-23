#define ll long long
#include <vector>
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        
        vector<ll int>pre(n,0);
        pre[0]=a[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+a[i];
        }
        
        vector<ll int>suff(n,0);
        suff[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]+a[i];
        }
        for(int i=0;i<n;i++)
        {
            ll int a=0;
            ll int b=0;
            if(i>0)
            {
                a=pre[i-1];
            }
            if(i<n-1)
            {
                b=suff[i+1];
            }
            if(a==b)
            {
                return i+1;
            }
        }
        return -1;
    }

};
