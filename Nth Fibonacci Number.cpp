class Solution 
{
  public:
    int nthFibonacci(int n)
    {
        //0 1 1 2 3 5
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        int a=0;
        int b=1;
        int mod=1e9+7;
        int c;
        for(int i=2;i<=n;i++)
        {
            c=(a+b)%mod;
            a=b;
            b=c;
        }
        return c;
    }
};
