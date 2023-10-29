class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        while(k>0)
        {
            n=n/2;
            k--;
        }
        return (n&1);
    }
};
