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


//Method-2 : 

class Solution
{
  public:
	int minDifference(int arr[], int n)  
    { 
        if(n==1)
        {
            return arr[0];
        }
       // vector<int>arr;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
           // arr.push_back(ar[i]);
        }
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));

        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(arr[0]<=sum)
        {
            dp[0][arr[0]]=true;
        }
        int res=INT_MAX;
        
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
            for(int k=1;k<=(sum/2);k++)
            {
                int diff=INT_MAX;
                if(dp[n-1][k]==true)
                {
                    diff=abs(sum-k-k);
                }
                res=min(res,diff);
            }
        
        return res;
	} 
};
