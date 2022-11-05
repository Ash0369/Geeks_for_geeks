class Solution 
{
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        vector<int>dp(100000,INT_MAX);
        queue<int>q;
        int steps=0;
        q.push(start);
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int node=q.front();
                if(node==end)
                {
                    return dp[end]+1;
                }
                q.pop();
                for(auto x:arr)
                {
                    int nz=(x*node)%100000;
                    if(dp[nz]>steps)
                    {
                        dp[nz]=steps;
                        q.push(nz);
                    }
                }
            }
            steps++;
        }
        
        if(dp[end]==INT_MAX)
        {
            return -1;
        }
        return dp[end]+1;
    }
};
