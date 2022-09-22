//Method-1 : 

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

//Method-2 : 

class Solution
{


	public:
	int minCoins(int vec[], int m, int v) 
	{ 
	    vector<vector<int>>dp(m+1,vector<int>(v+1,0));
	   for(int j=0;j<=v;j++)
	   {
	       dp[m][j]=INT_MIN;
	   }
	   
	   
	   
	   for(int index=m-1;index>=0;index--)
	   {
	       for(int target=1;target<=v;target++)
	       {
               int a=-1;
               if(target>=vec[index])
               {
                   a=1+dp[index][target-vec[index]];
               }
	           
               int b=dp[index+1][target];
               if(a<0)
               {
                   dp[index][target]=b;
               }
               else if(b<0)
               {
                   dp[index][target]=a;
               }
               else
               {
                   dp[index][target]=min(a,b);
               }
	       }
	   }
	   
	   if(dp[0][v]<=0)
	   {
	       return -1;
	   }
	   return dp[0][v];
	} 
	  
};
