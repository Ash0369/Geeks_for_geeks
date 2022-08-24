class Solution
{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        sort(arr2,arr2+n);
        vector<int>result;
        for(int i=0;i<m;i++)
        {
            auto y=upper_bound(arr2,arr2+n,arr1[i])-arr2;
            result.push_back(y);
        }
        return result;
    }
};
