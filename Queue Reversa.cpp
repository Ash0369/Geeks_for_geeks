class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        vector<int>v;
        while(!q.empty())
        {
           // cout<<q.front()<<endl;
            v.push_back(q.front());
            q.pop();
        }
        reverse(v.begin(),v.end());
        
        for(auto x:v)
        {
            q.push(x);
        }
        return q;
    }
};
