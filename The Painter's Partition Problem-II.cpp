bool place(long long int position,int arr[],int n,int k)
{
    int count=1;
    long long int sum=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>position)
        {
            return false;
        }
        if(sum+arr[i]<=position)
        {
            sum=sum+arr[i];
        }
        else
        {
            count++;
            sum=arr[i];
        }
    }
    if(count>k)
    {
        return false;
    }
    return true;
}
class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        //Finding search space
        //sort(arr,arr+n);
        int max_value=0;
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            max_value=max(max_value,arr[i]);
            sum=sum+arr[i];
        }
        int low=max_value;
        long long int high=sum;
        long long int res=high;
        while(low<=high)
        {
            long long int mid=(low+high)/2;
            if(place(mid,arr,n,k))
            {
                res=min(mid,res);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }   
        return res;
    }
};
