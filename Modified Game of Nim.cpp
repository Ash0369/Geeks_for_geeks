class Solution
{
public:
    int findWinner(int n, int A[])
    {
        int a=0;
        for(int i=0;i<n;i++)
        {
            a=a^A[i];
        }
        if(a==0)
        {
            return 1;
        }
        if(n%2==0)
        {
            return 1;
        }
        return 2;
        
    }
};
