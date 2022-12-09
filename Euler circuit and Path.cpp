class Solution 
{
public:
	int isEularCircuit(int v, vector<int>adj[])
	{
	    int odd=0;
	    int even=0;
	    for(int i=0;i<v;i++)
	    {
	       if(adj[i].size()%2==0)
	       {
	           even++;
	       }
	       else
	       {
	           odd++;
	       }
	    }
	    
	    if(even==v)
	    {
	        return 2;
	    }
	    else if(even==v-2 && odd==2)
	    {
	        return 1;
	    }
	    return 0;
	    
	    
	}
};
