class Solution 
{
  public:
    int solve(int a, int b) 
    {
        if(a==b)
        {
            return 0;
        }
        int x=max(a,b);
        int y=min(a,b);
        bool res=true;
        while(x>0 || y>0)
        {
            int set1=x&1;
            int set2=y&1;
            
            if(set2==1 && set1!=1)
            {
                res=false;
                break;
            }
            x=x>>1;
            y=y>>1;
        }
        if(res)
        {
            return 1;
        }
        return 2;
    }
};
