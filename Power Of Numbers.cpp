#define ll long long
#define mod 1000000007
ll int pwr(ll int a,ll int b)
{
    if(b==0)
        return 1;
    if(b%2==0){ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;return ans2;}
    ll int ans1=pwr(a,b/2);ll int ans2=(ans1*ans1)%mod;
    ans2=(ans2*a)%mod;
    return ans2;
}
class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       //Your code here
       return pwr(N,R);
        
    }

};
