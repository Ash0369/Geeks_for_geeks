class Solution 
{
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n)
    {
        sort(x.begin(),x.end(),greater<int>());
        sort(y.begin(),y.end(),greater<int>());
        int a=x.size();
        int b=y.size();
        int llim=0;
        int rlim=0;
        int cost=0;
        int rcut=1;
        int lcut=1;
        int score=0;
        for(int i=0;i<(a+b);i++)
        {
            if(llim<a && (rlim>=b || x[llim]>y[rlim]))
            {
                score=score+(rcut*x[llim]);
                lcut++;
                llim++;
            }
            else if(rlim<b && (llim>=a || x[llim]<y[rlim]))
            {
                score=score+(lcut*y[rlim]);
                rcut++;
                rlim++;
            }
            else if(x[llim]==y[rlim])
            {
                if(lcut>=rcut)
                {
                    score=score+(rcut*x[llim]);
                    lcut++;
                    llim++;
                }
                else
                {
                    score=score+(lcut*y[rlim]);
                    rcut++;
                    rlim++;
                }
            }
        }
        return score;
    }
};
