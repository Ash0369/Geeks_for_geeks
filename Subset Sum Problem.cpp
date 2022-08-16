//Method-1 : 

bool check(vector<int>&arr,int sum,int index,vector<vector<int>>&dp)
{
    if(sum==0)
    {
        return true;
    }
    if(index==0)
    {
        if(arr[0]==sum)
        {
            return true;
        }
        return false;
    }
    if(dp[index][sum]==-1)
    {
        bool pick=check(arr,sum-arr[index],index-1,dp);
        bool not_pick=check(arr,sum,index-1,dp);
    
        dp[index][sum]=pick|not_pick;
    }
    return dp[index][sum];
}
class Solution
{   
public:
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return check(arr,sum,n-1,dp);
    }
};


//Method-2 :

class Solution
{   
public:
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(arr[0]<=sum)
        {
            dp[0][arr[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool pick=false;
                if(j>=arr[i])
                {
                    pick=dp[i-1][j-arr[i]];
                }
                bool not_pick=dp[i-1][j];
                dp[i][j]=pick|not_pick;
            }
        }
        return dp[n-1][sum];
    }
};

//Method-3 : 

class Solution
{   
public:
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n=arr.size();
        vector<bool>dp(sum+1,false);
        vector<bool>curr(sum+1,false);
        
        dp[0]=true;
        curr[0]=true;
        
        if(arr[0]<=sum)
        {
            dp[arr[0]]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool pick=false;
                if(j>=arr[i])
                {
                    pick=dp[j-arr[i]];
                }
                bool not_pick=dp[j];
                curr[j]=pick|not_pick;
            }
            dp=curr;
        }
        return dp[sum];
    }
};
