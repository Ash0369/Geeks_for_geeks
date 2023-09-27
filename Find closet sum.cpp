class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //sort(arr,arr+n);
        //sort(brr,brr+m);
        
        int i=0;
        int j=m-1;
        int mn=1e9;
        vector<int>ans(2);
        while(i<n && j>=0)
        {
            int tot=arr[i]+brr[j];
            if(mn>abs(tot-x))
            {
                mn=abs(tot-x);
                ans[0]=arr[i];
                ans[1]=brr[j];
            }
            if(tot<=x)
            {
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
