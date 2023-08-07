class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int,int>,int>mp;
        for(int i=0;i<n;i++)
        {
            int g=__gcd(numerator[i],denominator[i]);
            mp[{numerator[i]/g,denominator[i]/g}]++;
        }
        
        
        int ans=0;
        for(auto x:mp)
        {
            int n=x.first.first;
            int d=x.first.second;
            
            int n_need=d-n;
            int d_need=d;
            
            int f=0;
            if(mp.find({n_need,d_need})!=mp.end())
            {
                f=mp[{n_need,d_need}];
            }
            
            if(f>0)
            {
                if(n==n_need && d==d_need)
                {
                    ans+=f*(f-1);
                }
                else
                {
                    ans+=(mp[{n,d}]*mp[{n_need,d_need}]);
                }
            }
        }
        return ans/2;
    }
};
