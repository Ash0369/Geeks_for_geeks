class Solution
{
    #define ll long long
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
        priority_queue<ll int,vector<ll int>,greater<ll int>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        ll int cost=0;
        while(pq.size()!=1)
        {
            ll int a=pq.top();
            pq.pop();
            ll int b=pq.top();
            cost+=a+b;
            pq.pop();
            
            pq.push(a+b);
        }
        
        return cost;
        
    }
};
