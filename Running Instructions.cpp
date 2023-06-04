string ans="NO";
void way(int index,int m,int tot,vector<int>&k,int n, vector<vector<int>>&dp)
{
    // 2 choice
    if(index==n)
    {
        if(tot==0)
        {
            ans="YES";
        }
        return;
    }
    
    if(dp[index][tot]!=-1)
    {
        return;
    }
    way(index+1,m,(tot+k[index])%m,k,n,dp);
    way(index+1,m,(m-tot+k[index])%m,k,n,dp);
    dp[index][tot]=1;
}
class Solution 
{
  public:
    string instructionCheck(int m, int n, vector<int> &k) 
    {
        ans="NO";
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        way(0,m,0,k,n,dp);
        return ans;
    }
};
