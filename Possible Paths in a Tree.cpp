class dsu
{
    vector<int>rank,parent,size;
    public:
    dsu(int n)
    {
        rank.resize(n+1,0);//Work for both 0 or 1 based
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int find_parent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=find_parent(parent[node]);//Path compression
    }

    void union_by_rank(int u,int v)
    {
        int ultimate_parent_u=find_parent(u);
        int ultimate_parent_v=find_parent(v);

        if(ultimate_parent_u==ultimate_parent_v)
        {
            //They are belonging to same component
            return;
        }
        parent[ultimate_parent_u]=ultimate_parent_v;
        
    }

    void union_by_size(int u,int v)
    {
        int ultimate_parent_u=find_parent(u);
        int ultimate_parent_v=find_parent(v);

        if(ultimate_parent_u==ultimate_parent_v)
        {
            //They are belonging to same component
            return;
        }
        else if(size[ultimate_parent_u]<=size[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
            size[ultimate_parent_v]+=size[ultimate_parent_u];
        }
        else if(size[ultimate_parent_u]>size[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
    }
};

bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[2]<v2[2])
    {
        return true;
    }
    return false;
}
class Solution
{
	public:
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
	    dsu ds(n+10);
	    sort(edges.begin(),edges.end(),cmp);
	    
	    vector<vector<int>>qe;
	    for(int i=0;i<q;i++)
	    {
	        qe.push_back({queries[i],i});
	    }
	    sort(qe.begin(),qe.end());
	    
	    int ptr=0;
	    int pos=0;
	    int ans=0;
	    map<int,int>mp;
	    for(int i=1;i<=n;i++)
	    {
	        mp[i]=1;
	    }
	    vector<int>res(q,0);
	    while(ptr<q)
	    {
	        while(pos<n-1 && edges[pos][2]<=qe[ptr][0])
	        {
	            int u=edges[pos][0];
	            int v=edges[pos][1];
	            int a=mp[ds.find_parent(u)];
	            int b=mp[ds.find_parent(v)];
	            ans-=(a*(a-1))/2;
	            ans-=(b*(b-1))/2;
	            ds.union_by_rank(u,v);
	            ans+=((a+b)*(a+b-1))/2;
	            mp[ds.find_parent(v)]=a+b;
	            pos++;
	        }
	        res[qe[ptr][1]]=ans;
	        ptr++;
	    }
	    return res;
	}
};
