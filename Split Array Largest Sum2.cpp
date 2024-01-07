bool check(int arr[],int n,int k,int s)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]>s)
        {
            return false;
        }
    }
    int till=1;
    int curr=0;
    for(int i=0;i<n;i++)
    {
        if((curr+arr[i])>s)
        {
            till++;
            curr=0;
        }
        curr+=arr[i];
    }
    if(till<=k)
    {
        return true;
    }
    return false;
}
class Solution {
  public:
    int splitArray(int arr[] ,int n, int k) 
    {
        int left=0;
        int right=1e9;
        
        int ans=0;
        
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(check(arr,n,k,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
