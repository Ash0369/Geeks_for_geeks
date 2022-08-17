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
        bool pick=false;
        if(sum>=arr[index])
        {
            pick=check(arr,sum-arr[index],index-1,dp);
        }
        bool not_pick=check(arr,sum,index-1,dp);
    
        dp[index][sum]=pick|not_pick;
    }
    return dp[index][sum];
}

class Solution
{
  public:
	int minDifference(int ar[], int n)  
    { 
        if(n==1)
        {
            return ar[0];
        }
        vector<int>arr;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+ar[i];
            arr.push_back(ar[i]);
        }
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int min_diff=INT_MAX;
        for(int i=1;i<=(sum/2);i++)
        {
            bool a=check(arr,i,n-1,dp);
            if(a==true)
            {
                int diff=abs(sum-i-i);
                min_diff=min(min_diff,diff);
            }
        }
        return min_diff;
	} 
};
