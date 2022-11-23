class Solution 
{
  public:
    long long int maxSumLCM(int n) 
    {
        #define ll long long
        ll sum=0;
        ll int left=1;
        ll int right=n;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                sum+=i;
                sum+=(n/i);
                
                if(i*i==n)
                {
                    sum-=i;
                }
            }
        }
        return sum;
    }
};
