#define ll long long
class Solution{
    public:
    long long MaxXP(int n, int k, ll int initial_exp, vector<int>& exp_req, vector<int>& exp_gain)
    {
        //ll int ans=intia
        vector<vector<int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({exp_req[i],exp_gain[i]});
        }
        sort(vec.begin(),vec.end());
        
        priority_queue<int>pq;
        
        int i=0;
        
        while(i< n && vec[i][0]<=initial_exp)
        {
            
            pq.push(vec[i][1]);
            i++;
        }
        while(k>0 && pq.size()>0)
        {
            initial_exp+=pq.top();
            k--;
            pq.pop();
            while(i< n && vec[i][0]<=initial_exp)
            {
                pq.push(vec[i][1]);
                i++;
            }
        }
        return initial_exp;
    }
};
