int coins(int vec[],int target,int index,int m,vector<vector<int>>&dp)
{
    if(index>=m || target<0)
    {
        return -1;
    }
    if(target==0)
    {
        return 0;
    }
    if(dp[index][target]==-1)
    {
        int a=1+coins(vec,target-vec[index],index,m,dp);
        int b=coins(vec,target,index+1,m,dp);
        if(a<=0)
        {
            dp[index][target]=b;
        }
        else if(b<=0)
        {
            dp[index][target]=a;
        }
        else
        {
             dp[index][target]=min(a,b);
        }
    }
    
    return dp[index][target];
}

class Solution
{


	public:
	int minCoins(int coin[], int M, int V) 
	{ 
	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	    int ans=coins(coin,V,0,M,dp);
	    if(ans<=0)
	    {
	        return -1;
	    }
	    
	    return ans;
	    
	} 
	  
};
