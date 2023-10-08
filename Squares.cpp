class Solution
{
    public:
    int squares(int N, int X)
    {
        long long int tot=1;
        for(int i=1;i<=2*N;i++)
        {
            tot=tot*2;
        }
        if(X>tot)
        {
            return -1;
        }
        int t=(X-1+2)/3;
        return t;
    }
};
