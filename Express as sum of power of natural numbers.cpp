#define ll long long

const int mod=1e9+7;
ll int dp[1000][1000];
ll int ways(int index,int n,vector<ll int>&sq)
{
    
    if(index==sq.size())
    {
        return n==0;
    }
    
    if(dp[index][n]!=-1)
    {
        return dp[index][n];
    }
    //not pick
    ll int ans1=ways(index+1,n,sq);
    
    //pick
    ll int ans2=0;
    if(sq[index]<=n)
    {
        ans2=ways(index+1,n-sq[index],sq);
    }
    return dp[index][n]=(ans1+ans2)%mod;
}
class Solution
{
    public:
    int numOfWays(int n, int x)
    {
        memset(dp,-1,sizeof(dp));
        vector<ll int>sq;
        for(int i=1;i<=1000;i++)
        {
            if(pow(i,x)>1000)
            {
                break;
            }
            sq.push_back(pow(i,x));
        }
        return ways(0,n,sq);
    }
};
