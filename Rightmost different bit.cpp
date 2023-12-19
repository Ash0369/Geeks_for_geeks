class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        if(m==n)
        {
            return -1;
        }
        for(int i=0;i<50;i++)
        {
            if((m&(1LL<<i))!=(n&(1LL<<i)))
            {
                return i+1;
            }
        }
        return -1;
    }
};
