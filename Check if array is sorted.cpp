class Solution 
{
  public:
    bool arraySortedOrNot(int arr[], int n) 
    {
        int prev=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=prev)
            {
                prev=arr[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
