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

//Method-2 : Using Priority Queue (Test cases are faulty according to striver)

class Solution
{
	public:
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int>distance(v,INT_MAX);
        vector<int>parent(v,-1);
        vector<bool>mst(v,false);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        distance[0]=0;
        parent[0]=-1;

        pq.push(make_pair(0,0));

        for(int i=0;i<v-1;i++) 
        {
            //Find element with minimum key value

            int node=pq.top().second;
            pq.pop();
            mst[node]=true;

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

                parent[x[0]]=node;
                distance[x[0]]=x[1];
                pq.push(make_pair(distance[x[0]],x[0]));
            }
        }
        int sum=0;
        for(auto x:distance)
        {
            sum=sum+x;
        }
        return sum;
    }
};
