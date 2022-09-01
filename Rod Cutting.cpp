//Method-1 : Breaking Recursivelly

int price_cal(int price[],int n,int index,int right,vector<vector<int>>&vec)
{
    if(index==0)
    {
        return price[right-1];
    }
    if(vec[index][right]==-1)
    {
        int cut=INT_MIN;
        if(index!=right)
        {
            cut=price[right-index-1]+price_cal(price,n,index-1,index,vec);
        }
        int not_cut=price_cal(price,n,index-1,right,vec);
        vec[index][right]=max(cut,not_cut);
    }
    return vec[index][right];
}
class Solution
{
  public:
    int cutRod(int price[], int n) 
    {
        vector<vector<int>>vec(n+1,vector<int>(n+1,-1));
        return price_cal(price,n,n,n,vec);
    }
};


//Method-2 : Breaking by tabulation

class Solution
{
  public:
    int cutRod(int price[], int n) 
    {  
        vector<vector<int>>vec(n+1,vector<int>(n+1,0));
        for(int j=1;j<=n;j++)
        {
            vec[0][j]=price[j-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int cut=INT_MIN;
                if(j>i)
                {
                    cut=price[j-i-1]+vec[i-1][i];
                }
                int not_cut=vec[i-1][j];
                vec[i][j]=max(cut,not_cut);
            }
        }
        
        return vec[n][n];
    }
};


//Method-3 : Breaking by space Optamization

class Solution
{
  public:
    int cutRod(int price[], int n) 
    {  
        vector<int>vec(n+1,0);
        vector<int>prev(n+1,0);
        for(int j=1;j<=n;j++)
        {
            vec[j]=price[j-1];
            prev[j]=price[j-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int cut=INT_MIN;
                if(j>i)
                {
                    cut=price[j-i-1]+vec[i];
                }
                int not_cut=vec[j];
                prev[j]=max(cut,not_cut);
            }
            vec=prev;
        }
        
        return vec[n];
    }
};


//Method-4 : Onlines of Infinite Knapsack problem : 

int cut(int price[],int index,int n,vector<vector<int>>&dp)
{
    if(index==0)
    {
        return 0;
    }
    if(dp[index][n]==-1)
    {
        int pick=INT_MIN;
        if(n>=index)
        {
            pick=price[index-1]+cut(price,index,n-index,dp);
        }
        int not_pick=cut(price,index-1,n,dp);
        dp[index][n]=max(pick,not_pick);
    }
    return dp[index][n];
}
class Solution
{
  public:
    int cutRod(int price[], int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return cut(price,n,n,dp);
    }
};

//Method-5 : 

class Solution
{
  public:
    int cutRod(int price[], int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int pick=INT_MIN;
                if(j>=i)
                {
                    pick=price[i-1]+dp[i][j-i];
                }
                int not_pick=dp[i-1][j];
                dp[i][j]=max(pick,not_pick);
            }
        }
        return dp[n][n];
    }
};

//Method-6 : 

class Solution
{
  public:
    int cutRod(int price[], int n) 
    {
        vector<int>dp(n+1,0);
        vector<int>prev(n+1,0);
        for(int j=0;j<=n;j++)
        {
            dp[j]=0;
            prev[j]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int pick=INT_MIN;
                if(j>=i)
                {
                    pick=price[i-1]+prev[j-i];
                }
                int not_pick=dp[j];
                prev[j]=max(pick,not_pick);
            }
            dp=prev;
        }
        return dp[n];
    }
};
