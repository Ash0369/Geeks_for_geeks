class Solution
{
    public:
    int setSetBit(int x, int y, int l, int r)
    {
        //cout<<y<<endl;
        int bit=1;
        int num=0;
        while(y>0)
        {
            int bit1=(y&1);
            if(bit>=l && bit<=r)
            {
               if(bit1)
               {
                   num=num|(1<<(bit-1));
               }
            }
            y=y>>1;
            bit++;
        }
       return num|x;
    }
};
