//Method-1 : DFS

class Solution
{
	public:
    void dfs(int node,stack<int>&st,vector<int>&visited,vector<int>adj[])
    {
        visited[node]=1;
        for(int it:adj[node])
        {
            if(!visited[it])
            {
                dfs(it,st,visited,adj);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int v, vector<int> adj[]) 
    {
           vector<int>visited(v,0);
           vector<int>result;
           stack<int>st;
           for(int i=0;i<v;i++)
           {
               if(!visited[i])
               {
                   dfs(i,st,visited,adj);
               }
           }
           while(!st.empty())
           {
               result.push_back(st.top());
               st.pop();
           }
           return result;
    }
}    

//Method-2 : BFS(Khan's Algorthim)

class Solution
{
	public:
        void bfs(int node,vector<int>&indegree,vector<int>&result,queue<int>&q,vector<int>adj[])
        {
            result.push_back(node);
            for(auto x:adj[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int>visited(v,0);
        vector<int>result;
        queue<int>q;
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++)
        {
            for(auto x:adj[i])
            {
                indegree[x]++;
            }
        }
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs(node,indegree,result,q,adj);
        }
        return result;
	}
};
