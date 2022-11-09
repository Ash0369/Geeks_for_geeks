int allocate(int index,int &weight,int curr_weight,int wt[],int val[],int &n, vector<vector<int>>&dp)
{
    if(index==n)
    {
        return 0;
    }
    if(dp[index][curr_weight]!=-1)
    {
        return dp[index][curr_weight];
    }
    int curr=wt[index];
    int not_take=allocate(index+1,weight,curr_weight,wt,val,n,dp);
    int take=0;
    if(curr_weight+curr<=weight)
    {
        take= val[index]+allocate(index+1,weight,curr_weight+curr,wt,val,n,dp);
    }
    return dp[index][curr_weight]=max(not_take,take);
}
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int mx_sum=0;
        for(int i=0;i<n;i++)
        {
            int x=wt[i];
            mx_sum+=x;
        }
        vector<vector<int>>dp(n+1,vector<int>(mx_sum+2,-1));
        return allocate(0,W,0,wt,val,n,dp);
    }
};
