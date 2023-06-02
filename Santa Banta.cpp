int dfs(int index,vector<vector<int>>&graph,vector<int>&dp)
{
    int ans=1;
    dp[index]=1;
    for(auto x:graph[index])
    {
        if(dp[x]==1)
        {
            continue;
        }
        ans+=dfs(x,graph,dp);
    }
    return ans;
}
class Solution
{
public:
    vector<int>prime;
    void precompute()
    {
        vector<int>dp(1000005,0);
        for(int i=2;i<=1000000;i++)
        {
            if(dp[i]==0)
            {
                prime.push_back(i);
                for(int j=2*i;j<=1000000;j=j+i)
                {
                    dp[j]=1;
                }
            }
        }
        
    }
    int helpSanta(int n, int m, vector<vector<int>> &g)
    {
        
        vector<int>dp(n+1,0);
        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==0)
            {
                k=max(k,dfs(i,g,dp));
            }
        }
        if(k==1)
        {
            return -1;
        }
        return prime[k-1];
        
    }
};
