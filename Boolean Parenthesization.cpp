int mod=1003;
int dp[205][205][3];
int dfs(int left,int right,string &s,int need)
{
    if(left>right)
    {
        return 0;
    }
    if(left==right)
    {
        if(s[left]=='T' && need==1)
        {
            return 1;
        }
        if(s[left]=='T' && need==0)
        {
            return 0;
        }
        if(s[left]=='F' && need==1)
        {
            return 0;
        }
        if(s[left]=='F' && need==0)
        {
            return 1;
        }
    }
    if(dp[left][right][need]!=-1)
    {
        return dp[left][right][need];
    }
    int ans=0;
    for(int i=left+1;i<=right-1;i=i+2)
    {
        int lt=dfs(left,i-1,s,1);
        int lf=dfs(left,i-1,s,0);
        
        int rt=dfs(i+1,right,s,1);
        int rf=dfs(i+1,right,s,0);
        
        if(need==1)
        {
            if(s[i]=='&')
            {
                ans=(ans+(lt*rt));
            }
            else if(s[i]=='^')
            {
                ans=(ans+(lt*rf));
                ans=(ans+(lf*rt));
            }
            else
            {
                ans=(ans+(lt*rf));
                ans=(ans+(lf*rt));
                ans=(ans+(lt*rt));
            }
        }
        else
        {
            if(s[i]=='&')
            {
                ans=(ans+(lt*rf));
                ans=(ans+(lf*rt));
                ans=(ans+(lf*rf));
            }
            else if(s[i]=='^')
            {
                ans=(ans+(lt*rt));
                ans=(ans+(lf*rf));
            }
            else
            {
                ans=(ans+(lf*rf));
            }
        }
        ans=ans%mod;
    }
    return dp[left][right][need]=ans;
}
class Solution
{
public:
    int countWays(int n, string s)
    {
        memset(dp,-1,sizeof(dp));
        return dfs(0,n-1,s,1);
    }
};
