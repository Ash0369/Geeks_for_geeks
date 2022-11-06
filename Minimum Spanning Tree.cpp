//Method-1 : Brute Force

class Solution
{
	public:
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int>distance(v,INT_MAX);
        vector<int>parent(v,-1);
        vector<bool>mst(v,false);

        distance[0]=0;
        parent[0]=-1;

        for(int i=0;i<v-1;i++) //As by v-1 last one will automattically get setted.
        {
            //Find element with minimum key value
            int node=0;
            int key_value=INT_MAX;
            for(int i=0;i<v;i++)
            {
                if((distance[i]<key_value) && mst[i]==false)
                {
                    key_value=distance[i];
                    node=i;
                }
            }

            //we have node as our minimum key value

            for(auto x:adj[node])
            {
                if(mst[x[0]]==true)
                {
                    continue;
                }
                if(x[0]==parent[node])
                {
                    continue;
                }

                if(x[1]>distance[x[0]])
                {
                    continue;
                }

                distance[x[0]]=x[1];
                parent[x[0]]=node;
            }
            mst[node]=true;
        }
        int sum=0;
        for(auto x:distance)
        {
            sum=sum+x;
        }
        return sum;
    }
};

//Method-2 : Using Priority Queue 

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
         int sum=0;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         
         pq.push({0,0});//Edgewt,node
         
         vector<bool>dp(v,false);
         
         while(!pq.empty())
         {
             auto node=pq.top();
             pq.pop();
             int pos=node.second;
             int edge=node.first;

             if(dp[pos]==true)
             {
                 continue;
             }
             sum+=edge;
             dp[pos]=true;
             for(auto x:adj[pos])
             {
                 if(dp[x[0]]==false)//Not visited
                 {
                     pq.push({x[1],x[0]});
                 }
             }
            
         }
         return sum;
    }
};


//Method-3 : Using Union by size

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
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>vec;
        for(int i=0;i<v;i++)
        {
            for(auto it:adj[i])
            {
                int node=it[0];
                int wt=it[1];
                
                vec.push_back({wt,{i,node}});
            }
        }
        
        sort(vec.begin(),vec.end());
        int mstwt=0;
        dsu ds(v);
        for(auto it:vec)
        {
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            
            if(ds.find_parent(u)!=ds.find_parent(v))
            {
                mstwt+=wt;
                ds.union_by_size(u,v);
            }
        }
        return mstwt;
    }
};

//Method-4 : Using Union by rank


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
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>vec;
        for(int i=0;i<v;i++)
        {
            for(auto it:adj[i])
            {
                int node=it[0];
                int wt=it[1];
                
                vec.push_back({wt,{i,node}});
            }
        }
        
        sort(vec.begin(),vec.end());
        int mstwt=0;
        dsu ds(v);
        for(auto it:vec)
        {
            int u=it.second.first;
            int v=it.second.second;
            int wt=it.first;
            
            if(ds.find_parent(u)!=ds.find_parent(v))
            {
                mstwt+=wt;
                ds.union_by_rank(u,v);
            }
        }
        return mstwt;
    }
};
