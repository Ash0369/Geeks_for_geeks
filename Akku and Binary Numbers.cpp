#define ll long long
class Solution
{
    
public:
    vector<ll int>vec;
    void precompute()
    {
        for(int i=0;i<63;i++)
        {
            for(int j=i+1;j<63;j++)
            {
               for(int k=j+1;k<63;k++)
               {
                   ll num=(1LL<<i)+(1LL<<j)+(1LL<<k);
                   vec.push_back(num);
               }
            }
        }
        sort(vec.begin(),vec.end());
    }
    
    long long solve(long long l, long long r)
    {
        int index=lower_bound(vec.begin(),vec.end(),l)-vec.begin();
        if(index==vec.size())
        {
            index--;
        }
        int index2=lower_bound(vec.begin(),vec.end(),r)-vec.begin();
        
        if(index2==vec.size())
        {
            index2--;
        }
        if((vec[index2])>r)
        {
            index2--;
        }
        return index2-index+1;
    }
};
