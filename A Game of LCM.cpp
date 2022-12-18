#define ll long long
class Solution 
{
  public:
    long long maxGcd(int n) 
    {
        ll int ans=n*(n-1);
        int k=2;
        for(ll int i=n-2;i>=1;i--)
        {
            if(__gcd(i,ans)==1)
            {
                ans=ans*i;
                k++;
                if(k==4)
                {
                    break;
                }
            }
        }
        return ans;
    }
};
