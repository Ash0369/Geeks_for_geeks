class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
          return *max_element(a.begin(),a.end());
    }
};
