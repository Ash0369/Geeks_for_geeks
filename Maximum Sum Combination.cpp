class Solution {
  public:
    vector<int> maxCombinations(int N, int k, vector<int> &A, vector<int> &B) 
    {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        int n=N;
        vector<int>ans;
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({A[i]+B[n-1],n-1});
        }
        while(!pq.empty() && k--)
        {
            ans.push_back(pq.top().first);
            int index=pq.top().second;
            
            pq.pop();
            
            if(index-1>=0)
            {
                pq.push({ans.back()-B[index]+B[index-1],index-1});
            }
        }
        return ans;
    }
};
