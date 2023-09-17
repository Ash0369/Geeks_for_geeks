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
        else if(rank[ultimate_parent_u]<=rank[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if(rank[ultimate_parent_u]>rank[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
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
class Solution {
public:
    
    bool check(int D, int N, vector<int> A) 
    {
        map<int,vector<int>>mp;
        
        int n=N;
        dsu ds(n+2);
        int d=D;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++)
        {
            int j=(i+D)%n;
            ds.union_by_rank(i,j);
        }
        for(int i=0;i<n;i++)
        {
            mp[ds.find_parent(i)].push_back(A[i]);
        }
        for(auto &x:mp)
        {
            sort(x.second.begin(),x.second.end());
            reverse(x.second.begin(),x.second.end());
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int p=ds.find_parent(i);
            ans.push_back(mp[p].back());
            mp[p].pop_back();
        }
        return is_sorted(ans.begin(),ans.end());
    }

};
