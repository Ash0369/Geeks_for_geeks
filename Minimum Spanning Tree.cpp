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
