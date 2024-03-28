void dfs(int index,vector<vector<vector<int>>>&graph,vector<int>&dp,int curr,int t)
{
    queue<vector<int>>q;
    q.push({0,index});
    
    dp[index]=0;
    
    
    while(!q.empty()){
        
        int index=q.front()[1];
        q.pop();
        if(dp[index]>t)
        {
            continue;
        }
    for(auto &x:graph[index])
    {
        int dist=x[0];
        int len=x[1];
        
        if(dp[dist]>(dp[index]+len))
        {
            dp[dist]=dp[index]+len;
            q.push({dp[dist],dist});
        }
    }
    }
}
class Solution 
{
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<vector<int>>>graph(n+10);
        for(auto x:edges)
        {
            int from=x[0];
            int to=x[1];
            
            int w=x[2];
            
            graph[from].push_back({to,w});
            graph[to].push_back({from,w});
        }
        
        int lowe=105;
        int num=105;
        
        for(int i=0;i<n;i++)
        {
            vector<int>dp(n+1,1e9);
            dfs(i,graph,dp,0,distanceThreshold);
            int ct=0;
            for(int i=0;i<n;i++)
            {
                if(dp[i]<=distanceThreshold)
                {
                    ct++;
                }
            }
            ct--;
            if(ct<lowe)
            {
                lowe=ct;
                num=i;
            }
            else if(ct==lowe)
            {
                num=i;
            }
        }
        return num;
    }
};
