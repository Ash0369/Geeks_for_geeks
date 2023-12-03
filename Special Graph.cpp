#define ll long long
class dsu
{
    vector<int>rank,parent,size;
    public:
    dsu(int n)
    {
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
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
        parent[ultimate_parent_u]=ultimate_parent_v;
        
    }

};
class Solution 
{
  public:
    long long solve(int n, vector<int>&vec) 
    {
        vector<vector<vector<int>>>edge((3*n)+2);
       
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n && (i*j)<=(2*n);j++)
            {
                int val=(1LL*i*j);
                val-=vec[i-1]%vec[j-1];
                val-=vec[j-1]%vec[i-1];
                if(abs(val)<=(n))
                {
                   // cout<<val<<" "<<i<<" "<<j<<endl;
                    edge[abs(val)].push_back({i,j});
                }
            }
        }
        dsu ds(n+2);
        //sort(edge.begin(),edge.end());
        ll int ans=0;
        for(int i=0;i<=3*n;i++)
        {
            for(auto &x:edge[i])
            {
                int i1=x[0];
                int j1=x[1];
                if(ds.find_parent(i1)!=ds.find_parent(j1))
                {
                    ans+=i;
                    ds.union_by_rank(i1,j1);
                }
            }
        }
        
        return ans;
    }
};
