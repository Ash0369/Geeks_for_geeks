class Solution
{
    public:
    int carpetBox(int A, int B, int C, int D)
    {
        int a=A;
        int b=B;
        int c=C;
        int d=D;
        
        int cnt=0;
        
        while(true)
        {
            bool loop=false;
            if(a>c && a>d)
            {
                loop=true;
                a=a/2;
                cnt++;
            }
            if(b>c && b>d)
            {
                loop=true;
                b=b/2;
                cnt++;
            }
            if(loop==false)
            {
                break;
            }
        }
        int z=min(a,b);
        int t=min(c,d);
        while(z>t)
        {
            z=z/2;
            cnt++;
        }
        return cnt;
    }
};
