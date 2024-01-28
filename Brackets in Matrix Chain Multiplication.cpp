#define ll long long
pair<ll int,string> dfs(int p[],int i,int j, vector<vector<pair<int,string>>>&dp)
{
    if(i==j)
    {
        string s="";
        s='A'+i-1;
        return {0,s};
    }
    if(dp[i][j].first!=-1)
    {
        return dp[i][j];
    }
    ll int till=1e18;
    string ans;
    for(int index=i;index<=j-1;index++)
    {
        auto r1=dfs(p,i,index,dp);
        auto r2=dfs(p,index+1,j,dp);
        
        ll int cost=r1.first+r2.first;
        cost+=p[i-1]*p[index]*p[j];
        
        string s="";
        s.push_back('(');
        s=s+r1.second;
        s+=r2.second;
        s.push_back(')');
        if(cost<till)
        {
            till=cost;
            ans=s;
        }
    }
    return dp[i][j]={till,ans};
}
class Solution
{
public:
    string matrixChainOrder(int p[], int n)
    {
        vector<vector<pair<int,string>>>dp(n+1,vector<pair<int,string>>(n+1,{-1,""}));
        auto f=dfs(p,1,n-1,dp);
        return f.second;
    }
};
