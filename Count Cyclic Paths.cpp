//METHOD-1 dp Give Runtime error


int mod=1e9+7;
//O->0
//A->1
//B->2
//C->3

//O-> A,B,C
//A->O,B
//B->O,A,C
//C->O,B
 vector<vector<int>>dp;
int ways(int curr,int n)
{
    if(n==0 && curr==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    int ans1=0;
    int ans2=0;
    int ans3=0;
    int ans4=0;
    if(dp[curr][n]!=-1)
    {
        return dp[curr][n];
    }
    if(curr==0 || curr==2 || curr==3)
    {
        ans1=ways(1,n-1);
    }
    if(curr!=2)
    {
        ans2=ways(2,n-1);
    }
    if(curr==0 || curr==2 || curr==1)
    {
        ans3=ways(3,n-1);
    }
    if(curr!=0)
    {
        ans4=ways(0,n-1);
    }
    
    
    return dp[curr][n]=((ans1+ans2)%mod+(ans3+ans4)%mod)%mod;
}
class Solution
{   
public:
    int countPaths(int N)
    {
        int n=N;
        dp.clear();
        dp.resize(4,vector<int>(n+1,-1));
        return ways(0,n);
    }
};


//Method-2 : 

int mod=1e9+7;
//O->0
//A->1
//B->2
//C->3

//O-> A,B,C
//A->O,B
//B->O,A,C
//C->O,B
class Solution
{   
public:
    int countPaths(int N)
    {
        int n=N;
        vector<vector<int>>dp(n+1,vector<int>(4,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=((dp[i-1][1]+dp[i-1][2])%mod+dp[i-1][3])%mod;
            dp[i][1]=((dp[i-1][0]+dp[i-1][2])%mod+dp[i-1][3])%mod;
            dp[i][2]=((dp[i-1][0]+dp[i-1][1])%mod+dp[i-1][3])%mod;
            dp[i][3]=((dp[i-1][0]+dp[i-1][1])%mod+dp[i-1][2])%mod;
        }
        return dp[n][0];
    }
};
