#define ll long long
int mod=1000000007;
class Solution{
    public:
    int orSum(int n, vector<int> a, int m, vector<int> b)
    {
        map<int,int>mp;
        for(auto x:b)
        {
            for(int i=0;i<31;i++)
            {
                if((x&(1<<i)))
                {
                    mp[i]++;
                }
            }
        }
        
        
        long long int ans=0;
        
        
        for(int i=0;i<n;i++)
        {
            int ele=a[i];
            for(int j=0;j<31;j++)
            {
                if((ele&(1<<j)))
                {
                    //take or with all this bit will always set in all cases 
                    ll int temp=1LL<<j;
                    temp=(temp*m)%mod;
                    ans=(ans+temp)%mod;
                }
                else
                {
                    //take with set
                    ll int temp=1LL<<j;
                    temp=(temp*mp[j])%mod;
                    ans=(ans+temp)%mod;
                }
            }
        }
        return ans;
    }
};
