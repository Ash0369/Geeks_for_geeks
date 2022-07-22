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
};
