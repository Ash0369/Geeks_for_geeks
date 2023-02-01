#define ll long long

//last=0 --> Red
//last=1 --> Green
//last=2 --> Blue
ll int paint(int n,int r[],int g[],int b[],int curr,int last,vector<vector<ll int>>&dp)
{
    if(curr==n)
    {
        return 0;
    }
    if(dp[curr][last]!=-1)
    {
        return dp[curr][last];
    }
    ll int c1=1e15;
    ll int c2=1e15;
    ll int c3=1e15;
    if(last!=1)
    {
        c1=r[curr]+paint(n,r,g,b,curr+1,1,dp);
    }
    if(last!=2)
    {
        c2=g[curr]+paint(n,r,g,b,curr+1,2,dp);
    }
    if(last!=3)
    {
        c3=b[curr]+paint(n,r,g,b,curr+1,3,dp);
    }
    
    return dp[curr][last]=min(c1,min(c2,c3));
}
class Solution
{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[])
    {
        int n=N;
        vector<vector<ll int>>dp(n+1,vector<ll int>(4,-1));
        return paint(n,r,g,b,0,0,dp);
    }
};
