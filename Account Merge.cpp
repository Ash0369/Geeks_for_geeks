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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        map<string,int>mp;
        
        int c=0;
        int n=accounts.size();
        dsu ds(n+10);
        for(auto x:accounts)
        {
            int p=0;
            for(auto y:x)
            {
                if(p==0)
                {
                    p=1;
                    continue;
                }
                if(mp.find(y)==mp.end())
                {
                    mp[y]=c;
                }
                else{
                    ds.union_by_rank(c,mp[y]);
                }
            }
            c++;
        }
        
        
        map<int,vector<string>>g;
        
        for(auto x:mp)
        {
            string mail=x.first;
            int p=x.second;
            p=ds.find_parent(p);
            g[p].push_back(mail);
        }
        
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++)
        {
            if(g[i].size()==0){
                continue;
            }
            sort(g[i].begin(),g[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto x:g[i])
            {
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
        
        
    }
};
