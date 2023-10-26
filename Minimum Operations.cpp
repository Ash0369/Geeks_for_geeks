class Solution
{
  public:
    int minOperation(int n)
    {
       int op=0;
       while(n>0)
       {
           op++;
           if(n&1)
           {
               op++;
           }
           n=n>>1;
       }
       return op-1;
    }
};
