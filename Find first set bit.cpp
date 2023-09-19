class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        int ans=0;
        if(n==0)
        {
            return 0;
        }
        while(true)
        {
            if((n&1))
            {
                return ans+1;
            }
            ans++;
            n=n/2;
        }
    }
};
