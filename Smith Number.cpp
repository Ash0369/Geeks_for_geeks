class Solution {
  public:
    int smithNum(int n) {
        int s=0;
        int h=n;
        int y=n;
        while(h>0)
        {
            s+=h%10;
            h=h/10;
        }
        for(int j=2;j*j<=n;j++)
        {
            while(n%j==0)
            {
                int k=j;
                while(k>0)
                {
                    s-=k%10;
                    k=k/10;
                }
                n=n/j;
            }
        }
        if(n==y)
        {
            return 0;
        }
        if(n>1)
        {
            while(n>0)
            {
                s=s-(n%10);
                n=n/10;
            }
        }
        return s==0;
    }
};
