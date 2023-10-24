int n;
int dp[505][505];
int dfs(int curr,int last,string &s)
{
    if(curr==n)
    {
        if(last==n)
        {
            return 0;
        }
        return 500;
    }
    if(dp[curr][last]!=-1)
    {
        return dp[curr][last];
    }
    int a=dfs(curr+1,last,s);
    int b=505;
    
    //do partiton
    int left=last;
    int right=curr;
    
    while(left<=right)
    {
        if(s[left]==s[right])
        {
            left++;
            right--;
        }
        else{
            break;
        }
    }
    if(left>right)
    {
        b=1+dfs(curr+1,curr+1,s);
    }
    return dp[curr][last]=min(a,b);
}
class Solution
{
public:
    int palindromicPartition(string s)
    {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,s)-1;
    }
};
