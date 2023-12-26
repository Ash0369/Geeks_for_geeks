class Solution {
  public:
    int countIndices(int n, vector<int> &arr) {
        vector<int>a=arr;
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=arr[i])
            {
                ans++;
            }
        }
        return ans;
    }
};
