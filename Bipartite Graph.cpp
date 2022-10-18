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
