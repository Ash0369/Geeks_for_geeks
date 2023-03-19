class Solution 
{
  public:
    int XOR(int n, int m) 
    {
        return n^m;
    }
    int check(int a, int b) 
    {
        a--;
        b=b>>a;
        if(b&1==1)
        {
            return 1;
        }
        return 0;
    }
    int setBit(int c, int d) 
    {
        int temp=1<<c;
        d=d|temp;
        return d;
    }
};
