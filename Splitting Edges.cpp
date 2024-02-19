void dfs(int index,int parent,vector<int>&values,vector<vector<int>>&tree,vector<vector<int>>&dp,vector<int>&h,int t)
{
    h[index]=t;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        dfs(x,index,values,tree,dp,h,t+1);
        dp[index][2]+=dp[x][2];
        dp[index][3]+=dp[x][3];
    }
    if(values[index]==2)
    {
        dp[index][2]++;
    }
    if(values[index]==3)
    {
        dp[index][3]++;
    }
}
class Solution
{
public:
    int splittingEdges(int n, vector<int> &values, vector<vector<int>> &edges)
    {
        vector<int>h(n+10,0);
        vector<vector<int>>dp(n+2,vector<int>(5,0));
        vector<vector<int>>tree(n+2);
        for(auto x:edges)
        {
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        dfs(0,-1,values,tree,dp,h,1);
        
        int ans=0;
        
        for(auto x:edges)
        {
            if(h[x[0]]>h[x[1]])
            {
                swap(x[0],x[1]);
            }
            
            int tot2=dp[0][2];
            int tot3=dp[0][3];
            
            //In down
            
            int d2=dp[x[1]][2];
            int d3=dp[x[1]][3];
            
            //In up
            
            int u2=tot2-d2;
            int u3=tot3-d3;
            
            
            if(d2>0 && d3>0 && u2>0 && u3>0)
            {
                ans++;
            }
        }
        return ans;
    }
};
