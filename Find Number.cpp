#define ll long long
class Solution
{
public:
    long long findNumber(long long N)
    {
        ll int n=N;
        vector<int>vec={9,1,3,5,7};
        ll int res=0;
        ll int mul=1;
        while(n>0)
        {
            int rem=n%5;
            res=res+(vec[rem]*mul);
            mul=mul*10;
            if(n%5==0)
            {
                n--;
            }
            n=n/5;
        }
        return res;
    }
};
