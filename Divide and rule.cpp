class Solution
{
    public:
    long numOfWays(int n)
    {
        #define ll long long
        if(n<=4)
        {
            return 0;
        }
        if(n%2!=0)
        {
            return 0;
        }
        int k=n/4;
        if(n%4==0)
        {
            return (k-1)*6;
        }
        return k*6;
    }
};
