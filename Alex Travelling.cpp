class Solution 
{
  public:
    #define pii pair<int,int>
    int minimumCost(vector<vector<int>>& flights, int n, int k) 
    {
        vector<vector<pii>>graph(n+1);
        for(auto x:flights)
        {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            graph[u].push_back({v,wt});
        }
        vector<int>dp(n+1,INT_MAX);
        dp[k]=0;
        
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            int already=node.first;
            for(auto x:graph[node.second])
            {
                int v=x.first;
                int wt=x.second;
                if(dp[v]>(wt+already))
                {
                    dp[v]=wt+already;
                    pq.push({dp[v],v});
                }
            }
        }
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==INT_MAX)
            {
                ans=-1;
                break;
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
