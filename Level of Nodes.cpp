class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<int>q;
	    q.push(0);
	    int level=0;
	    vector<int>dp(V+5,0);
	    while(!q.empty())
	    {
	        
	        int sz=q.size();
	        
	        for(int i=0;i<sz;i++)
	        {
	            int node=q.front();
	            if(node==X)
	            {
	                return level;
	            }
	            q.pop();
	            for(auto x:adj[node])
	            {
	                if(dp[x]==0)
	                {
	                    dp[x]=1;
	                    q.push(x);
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};
