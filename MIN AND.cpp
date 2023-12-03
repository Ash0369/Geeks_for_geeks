class Solution {
  public:
    long long solve(long long a, long long b) {
        long long int ans=0;
        bool g=false;
        
        for(int i=0;i<61;i++)
        {
            if((1LL<<i)>(max(a,b)))
            {
                break;
            }
            if((a&(1LL<<i)) && (b&(1LL<<i)))
            {
                
            }
            else if((a&(1LL<<i))==0 && (b&(1LL<<i))==0)
            {
                g=true;
            }
        }
        if(g)
        {
            return 0;
        }
        int i=0;
        if(((a&(1LL<<i)) + (b&(1LL<<i)))==1)
        {
            return 1;
        }
        return 2;
    }
};
