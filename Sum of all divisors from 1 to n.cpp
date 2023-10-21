#define ll long long
class Solution
{
public:
    long long sumOfDivisors(int n)
    {
        ll int ans=0;
        
        for(int i=1;i<=n;i++)
        {
            ans+=1LL*(n/i)*i;
        }
        return ans;
    }
};
