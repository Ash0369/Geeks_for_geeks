//Method-1 : BFS


class Solution 
{
public:
	bool isBipartite(int v, vector<int>adj[])
	{
	    vector<int>color(v,-1);
	    queue<int>q;
	    
	    for(int i=0;i<v;i++)
	    {
	        
	        if(color[i]==-1)
	        {
	            q.push(i);
	            color[i]=1;
	            while(!q.empty())
	            {
	                int n=q.front();
	                q.pop();
	                int curr=color[n];
	                for(auto x:adj[n])
	                {
	                    if(color[x]==-1)
	                    {
	                        color[x]=!curr;
	                        q.push(x);
	                    }
	                    else
	                    {
	                        if(color[x]==curr)
	                        {
	                            return false;
	                        }
	                    }
	                }
	            }
	        }
	    }
	    
	    return true;
	}

};


//Method- : DFS


bool dfs(int node,int intial,vector<int>adj[],vector<int>&color)
{
    if(color[node]!=-1)
    {
        if(color[node]==intial)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    color[node]=!intial;
    for(auto x:adj[node])
    {
        if(dfs(x,color[node],adj,color)==false)
        {
            return false;
        }
    }
    return true;
    
}
class Solution 
{
public:
	bool isBipartite(int v, vector<int>adj[])
	{
	    vector<int>color(v,-1);
	    
	    for(int i=0;i<v;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(dfs(i,0,adj,color)==false)
	            {
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};
