//Method-1 : 

int subsequence(string &s1,string &s2,int i,int j,vector<vector<int>>&dp)
{
    int ans;
    if(i<0 || j<0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s1[i]==s2[j])
    {
        ans=1+subsequence(s1,s2,i-1,j-1,dp);
    }
    else
    {
        ans=max(subsequence(s1,s2,i-1,j,dp),subsequence(s1,s2,i,j-1,dp));
    }
    return dp[i][j]=ans;
}
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return subsequence(s1,s2,x-1,y-1,dp);
    }
};

//Method-2 : 


class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        //dp[i][j]--> Max length got when pointing i on s1 and j on s2
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        if(s1[0]==s2[0])
        {
            dp[0][0]=1;
        }
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                if(i>0)
                {
                    dp[i][j]=dp[i-1][j];
                }
                if(j>0)
                {
                    dp[i][j]=max(dp[i][j],dp[i][j-1]);
                }
                if(s1[i]==s2[j] && i>0 && j>0)
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else if(s1[i]==s2[j])
                {
                    dp[i][j]=1;
                }
                
            }
        }
        
        return dp[x-1][y-1];
    }
};
