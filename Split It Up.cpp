#define ll long long

ll int dp[100005];
ll int ans=0;
void dfs(int index,int parent,vector<vector<int>>&tree)
{
    dp[index]=index;
    for(auto x:tree[index])
    {
        if(parent==x)
        {
            continue;
        }
        dfs(x,index,tree);
        dp[index]+=dp[x];
    }
    
}
void dfs2(int index,int parent,vector<vector<int>>&tree,ll int prev)
{
    ans=min(ans,abs(prev-dp[index]));
    for(auto x:tree[index])
    {
        if(parent==x)
        {
            continue;
        }
        dfs2(x,index,tree,dp[index]-dp[x]+prev);
    }
    
}
class Solution
{
    public:
    long long MinDiff(int n, int A[], int B[])
    {
        vector<vector<int>>tree(n+1);
        for(int i=0;i<n-1;i++)
        {
            tree[A[i]].push_back(B[i]);
            tree[B[i]].push_back(A[i]);
        }
        ans=1e18;
        memset(dp,0,sizeof(dp));
        dfs(1,-1,tree);
        dfs2(1,-1,tree,0);
        return ans;
    }
};
