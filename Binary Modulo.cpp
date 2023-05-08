#define ll long long
int mod;
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
        int modulo(string s,int m)
        {
            mod=m;
            int num=0;
            int p=0;
            for(int i=s.size()-1;i>=0;i--)
            {
               
                if(s[i]=='1')
                {
                    // cout<<p<<endl;
                    num=(num+(pwr(2,p)))%m;
                }
                p++;
            }
           // cout<<p<<endl;
            return num%m;
        }
};
