#define mod 1000000007
class Solution
{   
public:
    int waysToBreakNumber(int n)
    {
        long long int val=(1LL*(n+1)*(n+2))%mod;
        return (val*500000004)%mod;
    }
};
