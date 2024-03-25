vector<string>ans;
void dfs(int index,int d,int n,string &g)
{
    if(d<0)
    {
        return;
    }
    if(index==n)
    {
        ans.push_back(g);
        return;
    }
    g.push_back('1');
    dfs(index+1,d+1,n,g);
    g.pop_back();
    
    g.push_back('0');
    dfs(index+1,d-1,n,g);
    g.pop_back();
}
class Solution
{
public:	
	vector<string> NBitBinary(int n)
	{
	    ans.clear();
	    string g="";
	    dfs(0,0,n,g);
	    return ans;
	}
};
