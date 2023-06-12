#define ll long long
class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n) 
    {
        ll int s1=1LL*n*(n+1)/2;
        ll int s2=1LL*n*(n+1)*((2*n)+1)/6;
        
        ll int ss1=0;
        ll int ss2=0;
        for(auto x:arr)
        {
            ss1+=x;
            ss2+=1LL*x*x;
        }
        ll int v1=ss1-s1;
        ll int v2=ss2-s2;
        
        v2=v2/v1;
        
        ll int x=(v1+v2)/2;
        
        ll int y=x-v1;
        
        return {x,y};
    }
};
