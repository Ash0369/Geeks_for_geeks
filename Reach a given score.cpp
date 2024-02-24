#define ll long long

ll int dp[1000005][5];
ll int dfs(ll int n,int d)
{
        if(n<0)
        {
            return 0;
        }
        if(n==0)
        {
            return 1;
        }
        if(dp[n][d]!=-1)
        {
            return dp[n][d];
        }
        ll int a=0;
        ll int b=0;
        ll int c=dfs(n-10,2);
        
        if(d!=2)
        {
            b=dfs(n-5,1);
        }
        if(d==0)
        {
            a=dfs(n-3,0);
        }
        
        return dp[n][d]=(a+b+c);
}
class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
       for(int i=0;i<=n+2;i++)
       {
           dp[i][0]=-1;
           dp[i][1]=-1;
           dp[i][2]=-1;
           dp[i][3]=-1;
           
       }
       return dfs(n,0);
    }
};
