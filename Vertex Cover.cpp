int ans=0;
vector<vector<int>>test;

void generate(int index,int n,vector<int>&curr)
{
    if(index==n+1)
    {
        test.push_back(curr);
        return;
    }
    curr[index]=0;
    generate(index+1,n,curr);
    curr[index]=1;
    generate(index+1,n,curr);
    curr[index]=0;
}
void  dfs(int n,vector<vector<int>>&graph,vector<int>&dp)
{
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int c=dp[i];
            cnt+=c;
            if(c==0)
            {
                 for(auto x:graph[i])
                 {
                     if(dp[x]==0)
                     {
                         return;
                     }
                 }
            }
        }
        ans=min(ans,cnt);
}
class Solution
{
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) 
        {
            vector<vector<int>>graph(n+2);
            for(auto x:edges)
            {
                graph[x.first].push_back(x.second);
                graph[x.second].push_back(x.first);
            }
            test.clear();
            vector<int>curr(n+1,0);
            generate(1,n,curr);
            ans=n+10;
            for(auto x:test)
            {
                dfs(n,graph,x);
            }
            return ans;
        }
};
