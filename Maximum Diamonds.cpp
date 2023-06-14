class Solution 
{
  public:
    long long maxDiamonds(int A[], int N, int K) 
    {
        int n=N;
        int k=K;
        
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(A[i]);
        }
        long long int ans=0;
        while(k--)
        {
            int node=pq.top();
            ans+=node;
            pq.pop();
            pq.push(node/2);
        }
        return ans;
    }
};
