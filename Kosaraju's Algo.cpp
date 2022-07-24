class Solution
{
	public:

    void dfs(int node,vector<int> adj[],stack<int>&st,vector<int>&visited)
    {
        visited[node]=1;
        for(auto x:adj[node])
        {
            if(!visited[x])
            {
                dfs(x,adj,st,visited);
            }
        }
        st.push(node);
    }
    int kosaraju(int v, vector<int> adj[])
    {
        //Step-1 : Find Topo sort
        vector<int>visited(v,0);
        stack<int>st;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,st,visited);
            }
        }

        //Now st will have topo sort.
        //Step-2 : Transpose the graph
    
        vector<int>new_adj[v];
        for(int i=0;i<v;i++)
        {
            for(auto x:adj[i])
            {
                new_adj[x].push_back(i);
            }
        }

        //Now new_adj will have transpose graph

        //Step-3 : Take out element from stack and perform dfs

        for(int i=0;i<v;i++)
        {
            visited[i]=0;
        }

        vector<vector<int>>result;
        vector<int>temp;

        stack<int>dummy_stack;
        while(!st.empty())
        {
            int front=st.top();
            if(!visited[front])
            {
                dfs(front,new_adj,dummy_stack,visited);

                //Now dummy stack will contain our strongly coonected components.

                while(!dummy_stack.empty())
                {
                    temp.push_back(dummy_stack.top());
                    dummy_stack.pop();
                }
                result.push_back(temp);
                temp.clear();
            }
            st.pop();
        }
        return result.size();
    }
};
