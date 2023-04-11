class Solution 
{
public:
    int solve(int a, int b, int c) 
    {
        int mx=(max({a,b,c})+1)/2;
        int rem=0;
        rem=min({a,b,c})+(a+b+c-min({a,b,c})-max({a,b,c}));
        int gap=mx+1;
        rem=gap-rem;
        if(rem<3)
        {
            return a+b+c;
        }
        return -1;
    }
};
