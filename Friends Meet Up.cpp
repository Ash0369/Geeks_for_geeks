class Solution
{
    public:
    int friends(int N, int K, vector<int> start, vector<int> end)
    {
        int n=N;
        int k=K;
        vector<vector<int>>vec;
        
        for(int i=0;i<n;i++)
        {
            vec.push_back({start[i],end[i]});
        }
        sort(vec.begin(),vec.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int ans=0;
        int i=0;
        int d=1;
        
        while(!pq.empty() || i<n)
        {
            if(pq.size()==0)
            {
                d=vec[i][0];
            }
            while(i<n && vec[i][0]<=d)
            {
                pq.push(vec[i][1]);
                i++;
            }
            int cnt=0;
            while(!pq.empty() && cnt<k)
            {
                pq.pop();
                ans++;
                cnt++;
            }
            d++;
            while(!pq.empty() && pq.top()<d)
            {
                pq.pop();
            }
        }
        return ans;
        
        
    }
};
