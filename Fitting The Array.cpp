class Solution
{
public:
    
    bool isFit(int arr[], int brr[], int n)
    {
        int count=0;
        sort(arr,arr+n);
        sort(brr,brr+n);
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=brr[i])
            {
                count++;
            }
        }
        return count==n;
    }
};
