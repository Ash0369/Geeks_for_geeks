bool check(int mid,int arr[],int n,int k)
{
    int divide=0;
    int curr=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>mid)
        {
            return false;
        }
        if((curr+arr[i])>mid)
        {
            divide++;
            curr=arr[i];
        }
        else
        {
            curr+=arr[i];
        }
    }
    divide++;//Last curr stored is not divided
    if(divide<=k)
    {
        return true;
    }
    return false;
}
class Solution 
{
  public:
    int splitArray(int arr[] ,int n, int k) 
    {
        #define ll long long
        
        ll int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        
        int left=0;
        int right=sum;
        int ans=sum;
        while(left<=right)
        {
            int mid=(left+right)>>1;
            if(check(mid,arr,n,k))
            {
                ans=mid;
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
