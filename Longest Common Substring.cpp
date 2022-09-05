//Method-1 : 

class Solution 
{
public:
    int longestCommonSubstr(string text1,string text2,int n,int m) 
    {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        int max_value=0;
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                       dp[i][j]=1+dp[i-1][j-1];
                       max_value=max(max_value,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
             }
        }
        return max_value;
        
    }
};


//Method-2 : 

class Solution 
{
public:
    int longestCommonSubstr(string text1,string text2,int n,int m) 
    {
        int n1=text1.size();
        int n2=text2.size();
        vector<int>dp(n2+1,0);
        vector<int>prev(n2+1,0);
        int max_value=0;
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                       prev[j]=1+dp[j-1];
                       max_value=max(max_value,prev[j]);
                }
                else
                {
                    prev[j]=0;
                }
             }
             dp=prev;
        }
        return max_value;
        
    }
};
