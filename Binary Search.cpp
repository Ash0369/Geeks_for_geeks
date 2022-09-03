int search(int arr[],int l,int r,int k)
{
    if(r<l)
    {
        return -1;
    }
    int index=(l+r)/2;
    int ele=arr[index];
    if(ele==k)
    {
        return index;
    }
    if(ele>k)
    {
        return  search(arr,l,index-1,k);
    }
    
    return search(arr,index+1,r,k);
    
}
class Solution 
{
  public:
    int binarysearch(int arr[], int n, int k) 
    {
        return search(arr,0,n-1,k);
    }
};
