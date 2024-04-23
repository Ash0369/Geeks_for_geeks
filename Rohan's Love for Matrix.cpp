#define mod 1000000007
class Solution {
  public:
    int firstElement(int n) 
    {
        #define ll long long
        
        ll int a=1;
        ll int b=1;
        ll int c=1;
        ll int d=0;
        
        for(int i=2;i<=n;i++){
            ll int a1=(a+b)%mod;
            ll int b1=a;
            
            ll int c1=(c+d)%mod;
            ll int d1=c;
            
            a=a1;
            b=b1;
            c=c1;
            d=d1;
        }
        return c;
    }
};
