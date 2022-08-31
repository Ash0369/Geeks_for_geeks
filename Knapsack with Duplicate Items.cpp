//Method-1 : 

int duplicate(int val[],int wt[],int w,int index,vector<vector<int>>&dp)
{
    if(index==0 || w==0)
    {
        if(w>=wt[0])
        {
            return (val[0]*(w/wt[0]));
        }
        else
        {
            return 0;
        }
    }
    if(dp[index][w]==-1)
    {
        int not_pick=0+duplicate(val,wt,w,index-1,dp);
        int pick=0;
        if(w>=wt[index])
        {
            pick=val[index]+duplicate(val,wt,w-wt[index],index,dp);
        }
        dp[index][w]=max(pick,not_pick);
    }
    return dp[index][w];
    
}
class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return duplicate(val,wt,W,N-1,dp);
    }
};

//Method-2 : 

class Solution
{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        for(int j=0;j<=w;j++)
        {
            //int x=val[0]*(w/wt[j]);
            dp[0][j]=(j/wt[0])*val[0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                int not_pick=0+dp[i-1][j];
                int pick=0;
                if(j>=wt[i])
                {
                    pick=val[i]+dp[i][j-wt[i]];
                }
                dp[i][j]=max(pick,not_pick);
    
            }
        }
        return dp[n-1][w];
    }
};

//Method-3 :

class Solution
{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        
        vector<int>dp(w+1,0);
        vector<int>curr(w+1,0);
        for(int j=0;j<=w;j++)
        {
            dp[j]=(j/wt[0])*val[0];
            curr[j]=(j/wt[0])*val[0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                int not_pick=0+dp[j];
                int pick=0;
                if(j>=wt[i])
                {
                    pick=val[i]+curr[j-wt[i]];
                }
                curr[j]=max(pick,not_pick);
            }
            dp=curr;
        }
        return dp[w];
    }
};

//Method-4: 

class Solution
{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        
        vector<int>dp(w+1,0);
        for(int j=0;j<=w;j++)
        {
            dp[j]=(j/wt[0])*val[0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                int not_pick=0+dp[j];
                int pick=0;
                if(j>=wt[i])
                {
                    pick=val[i]+dp[j-wt[i]];
                }
                dp[j]=max(pick,not_pick);
            }
        }
        return dp[w];
    }
};
