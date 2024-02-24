class Solution
{
    public:
        int maxSum(int n)
        {
            int a=n/2;
            int b=n/3;
            int c=n/4;
            
            if((a+b+c)>n)
            {
                return maxSum(a)+maxSum(b)+maxSum(c);
            }
            return n;
        }
};
