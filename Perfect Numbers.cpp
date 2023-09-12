class Solution 
{
  public:
    int isPerfectNumber(long long N) 
    {
        #define ll long long
        ll int n=N;
        if(n==1)return 0;
        ll int s=0;
        for(ll int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                s=s+i;
                if(i!=(n/i))
                {
                    s=s+(n/i);
                }
            }
        }
        s++;
        return s==n;
    }
};
