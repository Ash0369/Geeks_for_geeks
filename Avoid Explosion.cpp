class dsu
{
    public:
    vector<int>rank,parent;
    dsu(int n)
    {
        rank.resize(n+1,0);
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
        return parent[node]=find_parent(parent[node]);
    }
    void uni(int u,int v)
    {
        int paru=find_parent(u);
        parent[find_parent(v)]=paru;
    }
};

class Solution 
{
  public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
    vector<vector<int>> danger, int m) 
    {
        dsu ds(n+1);
        vector<string>ans;
        for(auto x:mix)
        {
            int sol1=ds.find_parent(x[0]);
            int sol2=ds.find_parent(x[1]);
            bool res=true;
            for(int i=0;i<m;i++)
            {
                int p1=ds.find_parent(danger[i][0]);
                int p2=ds.find_parent(danger[i][1]);
                
                if((p1==sol1 && p2==sol2) || (p2==sol1 && p1==sol2))
                {
                    res=false;
                    break;
                }
            }
            if(res)
            {
                ds.uni(x[0],x[1]);
                ans.push_back("Yes");
            }
            else
            {
                ans.push_back("No");
            }
        }
        return ans;
    }
};
