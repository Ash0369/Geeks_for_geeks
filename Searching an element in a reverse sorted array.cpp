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
        return 1;
    }
    if(ele<k)
    {
        return  search(arr,l,index-1,k);
    }
    
    return search(arr,index+1,r,k);
    
}
class Solution
{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int n, int k) 
    { 
    
       //We want searching in reverse sorted array.
       
       //We will reverse array
       
       reverse(arr,arr+n);
       
       return search(arr,0,n-1,k);
       
       
    }
};
