class Solution {
  public:
    int minimizeArrayScore(int n, vector<int> &arr) {
       sort(arr.begin(),arr.end());
       
       int i=0;
       int j=n-1;
       int ans=arr[i]+arr[j];
       
       while(i<j)
       {
           ans=max(ans,arr[i]+arr[j]);
           i++;
           j--;
       }
       
       return ans;
    }
    
};
