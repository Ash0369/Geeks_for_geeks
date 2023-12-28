bool dfs(int x,int y,string &wild, string &pattern,vector<vector<int>>&dp)
{
    int n=wild.size();
    int m=pattern.size();
    
    if(x>=n && y>=m)
    {
        return true;
    }
    if(x>=n || y>=m)
    {
        return false;
    }
    
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    if(wild[x]==pattern[y])
    {
        return dfs(x+1,y+1,wild,pattern,dp);
    }
    if(wild[x]=='?')
    {
        return dfs(x+1,y+1,wild,pattern,dp);
    }
    if(wild[x]=='*')
    {
        return dfs(x+1,y+1,wild,pattern,dp) | dfs(x,y+1,wild,pattern,dp);
    }
    return false;
}
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int n=wild.size();
        int m=pattern.size();
        
        vector<vector<int>>dp(n+10,vector<int>(m+10,-1));
        
        return dfs(0,0,wild,pattern,dp);
    }
};
