class Solution{
  public:
    int findMaxAverage(int a[], int n) {
       sort(a,a+n);
       return a[n-1];
    }
};
