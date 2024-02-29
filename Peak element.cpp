class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        int left=0;
        int right=n-1;
        if(n==1)
        {
            return 0;
        }
        int ans=-1;
        
        while(left<=right)
        {
            int mid=(right-left)/2;
            mid+=left;
            if(mid==0)
            {
                if(arr[mid]>arr[mid+1])
                {
                    return mid;
                }
                left=mid+1;
            }
            else if(mid==n-1)
            {
                if(arr[mid]>arr[mid-1])
                {
                    return mid;
                }
                right=mid-1;
            }
            else
            {
                if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                {
                    return mid;
                }
                if(arr[mid+1]>arr[mid])
                {
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
    }
};
