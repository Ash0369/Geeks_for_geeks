//Method-1 : 

int paint(vector<vector<int>> &colors,int index,int n,int last,vector<vector<int>>&dp)
{
    if(index==n)
    {
        return 0;
    }
    if(dp[index][last]!=-1)
    {
        return dp[index][last];
    }
    int ans=INT_MAX;
    for(int i=0;i<3;i++)
    {
        if(i==last)
        {
            continue;
        }
        int cost=colors[index][i]+paint(colors,index+1,n,i,dp);
        ans=min(ans,cost);
    }
    return dp[index][last]=ans;
}

class Solution
{   
public:
    int minCost(vector<vector<int>> &colors, int N) 
    {
        int n=N;
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return paint(colors,0,n,3,dp);
    }
};


//Method-2 : 

int paint(vector<vector<int>> &colors,int index,int n,int last,vector<vector<int>>&dp)
{
    if(index==n)
    {
        return 0;
    }
    if(dp[index][last]!=-1)
    {
        return dp[index][last];
    }
    int ans=INT_MAX;
    for(int i=0;i<3;i++)
    {
        if(i==last)
        {
            continue;
        }
        int cost=colors[index][i]+paint(colors,index+1,n,i,dp);
        ans=min(ans,cost);
    }
    return dp[index][last]=ans;
}

class Solution
{   
public:
    int minCost(vector<vector<int>> &colors, int N) 
    {
        int n=N;
        vector<vector<int>>dp(n+1,vector<int>(3,0));
        for(int i=n-1;i>=0;i--)
        {
            dp[i][0]=colors[i][0]+min(dp[i+1][1],dp[i+1][2]);
            dp[i][1]=colors[i][1]+min(dp[i+1][0],dp[i+1][2]);
            dp[i][2]=colors[i][2]+min(dp[i+1][1],dp[i+1][0]);
        }
        return min(dp[0][0],min(dp[0][1],dp[0][2]));
    }
};
