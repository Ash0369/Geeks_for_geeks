class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int>ans={-1,-1};
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            
            if(arr[mid]==x)
            {
                ans[0]=mid;
                right=mid-1;
            }
            else if(arr[mid]>x)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        left=0;
        right=n-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(arr[mid]==x)
            {
                ans[1]=mid;
                left=mid+1;
            }
            else if(arr[mid]>x)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};
