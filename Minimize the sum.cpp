class Solution 
{
public:
    int minimizeSum(int N, vector<int> arr) 
    {
        int n=N;
        if(n==1)
        {
            return 0;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto x:arr)
        {
            pq.push(x);
        }
        int s=0;
        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            s+=a+b;
            pq.push(a+b);
        }
        return s;
    }
};
