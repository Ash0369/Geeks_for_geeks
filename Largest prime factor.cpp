class Solution
{
public: 
    long long int largestPrimeFactor(int N)
    {
        int n=N;
        int ans=1;
        for(int i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                n=n/i;
                ans=max(ans,i);
            }
        }
        if(n>1)
        {
            ans=max(ans,n);
        }
        return ans;
    }
};
