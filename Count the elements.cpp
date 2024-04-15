class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
    int q) 
    {
        sort(b.begin(),b.end());
        vector<int>ans;
        
        for(auto y:query)
        {
            int x=a[y];
            auto lb=upper_bound(b.begin(),b.end(),x);
            lb--;
            int ans1=lb-b.begin();
            ans.push_back(ans1+1);
        }
        return ans;
    }
};
