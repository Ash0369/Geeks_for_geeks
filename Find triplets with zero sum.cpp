class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            int low=i+1;
            int high=n-1;
            while(low<high)
            {
                int s=arr[i]+arr[low]+arr[high];
                if(s==0)
                {
                    return true;
                }
                if(s>0)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
            
            
        }
        return false;
    }
};
