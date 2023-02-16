bool dfs(int index,vector<int>&arr,vector<int>&dp)
{
    dp[index]=1;
    int jump=index+arr[index];
    if(jump>=arr.size() || jump<0)
    {
        dp[index]=2;
        return true;
    }
    if(dp[jump]==0)
    {
        if(dfs(jump,arr,dp))
        {
            dp[index]=2;
            return true;
        }
    }
    if(dp[jump]==2)
    {
        dp[index]=2;
        return true;
    }
    return false;
}
class Solution
{
public:
    int goodStones(int n,vector<int> &arr)
    {
        vector<int>dp(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(dp[i]==0)
            {
                dfs(i,arr,dp);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==2)
            {
                cnt++;
            }
        }
        return cnt;
    }  
};
