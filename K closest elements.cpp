class Solution {
  public:
    vector<int> printKClosest(vector<int>&arr, int n, int k, int x) {
       vector<vector<int>>vec;
       
       for(auto x1:arr)
       {
           if(x1==x)
           {
               continue;
           }
           vec.push_back({abs(x1-x),-1*x1});
       }
       sort(vec.begin(),vec.end());
       reverse(vec.begin(),vec.end());
       vector<int>ans;
       while(k--)
       {
           ans.push_back(-1*vec.back()[1]);
           vec.pop_back();
       }
       return ans;
    }
};
