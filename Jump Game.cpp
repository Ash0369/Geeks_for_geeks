//Method-1 : 

int dfs(int arr[],int index,int n)
{
    if(index==n)
    {
        return 0;
    }
    if(index==n-1)
    {
        return 1;
    }
    int mx_jmp=arr[index];
    for(int i=1;i<=mx_jmp;i++)
    {
        if(dfs(arr,index+i,n))
        {
            return 1;
        }
    }
    return 0;
}
class Solution 
{
  public:
    int canReach(int arr[], int n) 
    {
        return dfs(arr,0,n);
    }
};

//Method-2 : 

int dfs(int arr[],int index,int &n,vector<int>&dp)
{
    if(index==n)
    {
        return 0;
    }
    if(index==n-1)
    {
        return 1;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int mx_jmp=arr[index];
    for(int i=1;i<=mx_jmp;i++)
    {
        if(dfs(arr,index+i,n,dp))
        {
            return dp[index]=1;
        }
    }
    dp[index]=0;
    return 0;
}
class Solution 
{
  public:
    int canReach(int arr[], int n) 
    {
        vector<int>dp(n+1,-1);
        return dfs(arr,0,n,dp);
    }
};
