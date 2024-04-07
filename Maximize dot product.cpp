int dp[1001][1001];
int dfs(int i,int j,int n,int m,int a[],int b[])
{
    if(j==m && i==n)
    {
        return 0;
    }
    if(j==m)
    {
        return 0;
    }
    if(i==n)
    {
        return -10000000;
    }
    
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int a1=a[i]*b[j];
    a1+=dfs(i+1,j+1,n,m,a,b);
    
    int b1=dfs(i+1,j,n,m,a,b);
    
    return dp[i][j]=max(a1,b1);
}

class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{
	    memset(dp,-1,sizeof(dp));
	    return dfs(0,0,n,m,a,b);
	} 
};
