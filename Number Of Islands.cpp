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
        else if(rank[ultimate_parent_u]<rank[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
        }
        else if(rank[ultimate_parent_u]>rank[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
        }
        else if(rank[ultimate_parent_u]==rank[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
            rank[ultimate_parent_u]++;
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
        else if(size[ultimate_parent_u]<size[ultimate_parent_v])
        {
            parent[ultimate_parent_u]=ultimate_parent_v;
            size[ultimate_parent_v]+=size[ultimate_parent_u];
        }
        else if(size[ultimate_parent_u]>size[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
        else if(size[ultimate_parent_u]==size[ultimate_parent_v])
        {
            parent[ultimate_parent_v]=ultimate_parent_u;
            size[ultimate_parent_u]+=size[ultimate_parent_v];
        }
    }

};
class Solution 
{
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
    {
        dsu ds(n*m);
        
        vector<int>vec(n*m+2,0);
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int no_of_island=0;
        vector<int>ans;
        for(auto x:operators)
        {
            if(vec[(x[1]*n)+(x[0]+1)]==1)
            {
                ans.push_back(no_of_island);
                continue;
            }
            int x_cor=x[0];
            int y_cor=x[1];
            vec[(y_cor*n)+(x_cor+1)]=1;
            int counter=-1;
            for(int i=0;i<4;i++)
            {
                int new_x=x_cor+dx[i];
                int new_y=y_cor+dy[i];
                
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && vec[(new_y*n)+(new_x+1)]==1)
                {
                    if(ds.find_parent((y_cor*n)+(x_cor+1))!=ds.find_parent((new_y*n)+(new_x+1)))
                    {
                        counter++;
                        ds.union_by_rank(ds.find_parent((y_cor*n)+(x_cor+1)),ds.find_parent((new_y*n)+(new_x+1)));
                    }
                }
            }
            no_of_island-=counter;
            ans.push_back(no_of_island);
        }
        return ans;
    }
};
