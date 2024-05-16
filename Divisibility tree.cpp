int ans=0;
int dfs(int index,int parent,vector<vector<int>>&tree)
{
    int odd=0;
    int even=0;
    for(auto x:tree[index])
    {
        if(x==parent)
        {
            continue;
        }
        int a=dfs(x,index,tree);
        if(a==0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    
    //Which all are even they are gone
    ans+=even;
    
    //Now we have some odd i have to take together all these
    
    if(odd%2==0)
    {
        return 1;
    }
    return 0;
}
class Solution {
public:
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    
	    //we need 2 node in each
	    
	    vector<vector<int>>tree(n+5);
	    
	    for(auto x:edges)
	    {
	        tree[x[0]].push_back(x[1]);
	        tree[x[1]].push_back(x[0]);
	    }
	    
	    ans=0;
	    
	    dfs(1,-1,tree);
	    return ans;
	    
	}
};
