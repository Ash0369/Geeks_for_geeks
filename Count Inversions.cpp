#define ll long long
ll int merge(int left,int mid,int right,ll int arr[])
{
    ll int cnt=0;
    int aptr=left;
    int bptr=mid+1;
    int i=0;
    vector<ll int>temp;
    while(aptr<=mid && bptr<=right)
    {
        if(arr[aptr]>arr[bptr])
        {
            temp.push_back(arr[bptr]);
            cnt+=mid-aptr+1;
            bptr++;
        }
        else
        {
            temp.push_back(arr[aptr]);
            aptr++;
        }  
    }
    while(aptr<=mid)
    {
        temp.push_back(arr[aptr]);
        aptr++;
    }
    
    while(bptr<=right)
    {
         temp.push_back(arr[bptr]);
         bptr++;
    }
    
    int ptr=0;
    for(int i=left;i<=right;i++)
    {
        arr[i]=temp[ptr];
        ptr++;
    }
    return cnt;
}

ll int merge_sort(ll int arr[], int left,int right)
{
    ll int ans=0;
    if(left>=right)
        return 0;
    int mid=(left+right)/2;
    ans+=merge_sort(arr,left,mid);
    ans+=merge_sort(arr,mid+1,right);
    ans+=merge(left,mid,right,arr);
    return ans;
}

class Solution
{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        int n=N;
        return merge_sort(arr,0,n-1);
    }

};
