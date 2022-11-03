//Method-1 : Priority queue

class Solution
{
	public:
    vector <int> dijkstra(int v, vector<vector<int>>adj[], int s)
    {
        vector<int>distance(v,INT_MAX);
        distance[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push(make_pair(0,s));
        while(!pq.empty())
        {
            int front=pq.top().second;
            pq.pop();
            for(auto ele:adj[front]) //ele will contain all vectors which are adjcent to nodes
            {
                if(distance[ele[0]]>(distance[front]+ele[1]))
                {
                    distance[ele[0]]=distance[front]+ele[1];
                    pq.push(make_pair(distance[ele[0]],ele[0]));
                }
            }
        }
        return distance;
    }
};


//Method-2 : Using Set

class Solution
{
	public:
    vector <int> dijkstra(int v, vector<vector<int>>adj[], int s)
    {
        vector<int>distance(v,INT_MAX);
        distance[s]=0;
        set<pair<int,int>>st;
        st.insert(make_pair(0,s));
        while(!st.empty())
        {
            auto node=st.begin();
            st.erase(node);
            int front=(*node).second;
            for(auto ele:adj[front]) //ele will contain all vectors which are adjcent to nodes
            {
                if(distance[ele[0]]>(distance[front]+ele[1]))
                {
                    st.erase({distance[ele[0]],ele[0]});
                    distance[ele[0]]=distance[front]+ele[1];
                    st.insert(make_pair(distance[ele[0]],ele[0]));
                }
            }
        }
        return distance;

    }
};
