int longest(string &text1,string &text2,int x1,int x2,vector<vector<int>>&dp)
{
    if(x1<0 || x2<0)
    {
        return 0;
    }
    if(text1[x1]==text2[x2])
    {
       return 1+ longest(text1,text2,x1-1,x2-1,dp);
    }
    else
    {
        if(dp[x1][x2]==-1)
        {
            int a=longest(text1,text2,x1-1,x2,dp);
            int b=longest(text1,text2,x1,x2-1,dp);
            dp[x1][x2]=max(a,b);
        }
        return dp[x1][x2];
    }
}
class Solution 
{
public:
    int minInsertions(string s) 
    {
        int n=s.length();
        string a=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int c=longest(a,s,n-1,n-1,dp);
        if(c!=0)
            return s.length()-c;
        else
            return s.length();
    }
};
