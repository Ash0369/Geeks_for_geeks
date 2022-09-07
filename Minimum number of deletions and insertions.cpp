int lcs(string s1,string s2,int x,int y,vector<vector<int>>&dp)
{
    if(x<0 || y<0)
    {
        return 0;
    }
    if(s1[x]==s2[y])
    {
        return 1+lcs(s1,s2,x-1,y-1,dp);
    }
   
    if(dp[x][y]==-1)
    {
         int a=lcs(s1,s2,x-1,y,dp);
         int b=lcs(s1,s2,x,y-1,dp);
         
         dp[x][y]=max(a,b);
    }
    
    return dp[x][y];
}
class Solution
{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int m=str1.length();
	    int n=str2.length();
	    vector<vector<int>>dp(m,vector<int>(n,-1));
	    int temp=lcs(str1,str2,str1.length()-1,str2.length()-1,dp);
	    return str1.length()+str2.length()-(2*temp);
	} 
};
