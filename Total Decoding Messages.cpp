#define ll long long
int mod=1e9+7;
ll int ways(string &str,int index,vector<ll int>&dp)
{
    int n=str.size();
    ll int way1=0;
    ll int way2=0;
    if(index==n)
    {
        return 1;
    }
    if(str[index]=='0')
    {
        return 0;
    }
    
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    way1=ways(str,index+1,dp);
    
    if(index<n-1)
    {
        int c1=str[index]-'0';
        int c2=str[index+1]-'0';
        if((c1==2 && c2<=6 ) || (c1==1))
        {
            way2=ways(str,index+2,dp);
        }
        
    }
    return dp[index]=(way1+way2)%mod;
}
class Solution 
{
	public:
		int CountWays(string str)
		{
		    int n=str.size();
		    vector<ll int>dp(n+1,-1);
		    return ways(str,0,dp);
		}

};
