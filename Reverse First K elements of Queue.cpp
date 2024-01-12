class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) 
    {
        vector<int>vec;
        while(q.size()>0)
        {
            vec.push_back(q.front());
            q.pop();
        }
        for(int i=k-1;i>=0;i--)
        {
            q.push(vec[i]);
        }
        for(int i=k;i<vec.size();i++)
        {
            q.push(vec[i]);
        }
       
        return q;
    }
};
