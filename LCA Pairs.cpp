#define ll long long

int n;
vector<ll int>ans1;
int dfs(int index,int parent,vector<vector<int>>&tree)
{
    ll int ans=0;
    ll int sum=0;
    for(auto x:tree[index])
    {
        if(x==parent) continue;
        
        ll int cnt=dfs(x,index,tree);
        ans+=sum*cnt;
        sum+=cnt;
    }
    ans+=sum+1;
    ans1[index]=ans;
    return sum+1;
}
class Solution 
{
    public:
	
	vector<long long>calcPairs(int N, vector<int> p)
	{
	    n=N;
	    vector<vector<int>>tree(n+1);
	    for(int i=0;i<n;i++)
	    {
	        if(p[i]!=-1)
	        {
	            tree[i].push_back(p[i]);
	            tree[p[i]].push_back(i);
	        }
	    }
	    ans1.resize(n,0);
	    dfs(0,-1,tree);
	    return ans1;
	}
};
