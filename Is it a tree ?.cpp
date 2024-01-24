bool dfs(vector<int>&dp,int index,int parent,vector<vector<int>>&tree)
{
    dp[index]=1;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        
        if(dp[x]==1)
        {
            //cout<<index<<" "<<x<<endl;
            return false;
        }
        if(dfs(dp,x,index,tree))
        {
            
        }
        else{
            return false;
        }
    }
    return true;
}
class Solution 
{
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) 
    {
        vector<vector<int>>tree(n+2);
        for(auto x:adj)
        {
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        vector<int>dp(n+1,0);
        
        bool res=dfs(dp,0,-1,tree);
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]==0)
            {
               // cout<<i<<endl;
                res=false;
            }
        }
        return res;
    }
};
