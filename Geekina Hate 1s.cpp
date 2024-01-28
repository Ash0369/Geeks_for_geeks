#define ll long long

ll int dp[70][5][70];
ll int dfs(string &s,int index,int tight,int k)
{
    if(k<0)
    {
        return 0;
    }
    if(index==s.size())
    {
        return 1;
    }
    if(dp[index][tight][k]!=-1)
    {
        return dp[index][tight][k];
    }
    int ub=s[index]-'0';
    if(tight==0)
    {
        ub=1;
    }
    ll int ans=0;
    for(int dig=0;dig<=ub;dig++)
    {
        if(dig==ub)
        {
            ans+=dfs(s,index+1,tight,k-dig);
        }
        else
        {
            ans+=dfs(s,index+1,0,k-dig);
        }
    }
    return dp[index][tight][k]=ans;
    
}
bool check(ll int mid,int n,int k)
{
    //How many number<=mid having atmost k set bits
    memset(dp,-1,sizeof(dp));
    string s="";
    while(mid>0)
    {
        if((mid&1))
        {
            s.push_back('1');
        }
        else
        {
            s.push_back('0');
        }
        mid=mid/2;
    }
    reverse(s.begin(),s.end());
    ll int g=dfs(s,0,1,k);
    if(g>=n)
    {
        return true; 
    }
    return false;
}
class Solution 
{
  public:
    long long findNthNumber(int n, int k) 
    {
        ll int left=1;
        ll int right=1e18;
        ll int ans=-1;
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            if(check(mid,n,k))
            {
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
