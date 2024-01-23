class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>>graph(n+1);
        vector<int>out(n+1,0);
        for(auto x:prerequisites)
        {
            out[x[0]]++;
            graph[x[1]].push_back(x[0]);
        }
        
        vector<int>ans;
        
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(out[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto x:graph[node])
            {
                out[x]--;
                
                if(out[x]==0)
                {
                    q.push(x);
                }
            }
        }
        
        if(ans.size()==n)
        {
            return ans;
        }
        return {};
    }
};
