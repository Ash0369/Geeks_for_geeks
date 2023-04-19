//Method-1 : 

class Solution
{
    public:
    int kthSmallest(int arr[], int l, int r, int k) 
    {
        int n=r-l+1;
        sort(arr,arr+n);
        return arr[k-1];
    }
};

//Method-2 : Quick select


int indx;
int quick(int arr[],int l,int r)
{
   
    int grt=l;
    int pivot=arr[r];
    for(int i=l;i<r;i++)
    {
        if(arr[i]>pivot)
        {
            continue;
        }
        swap(arr[i],arr[grt]);
        grt++;
    }
    swap(arr[r],arr[grt]);
    if(indx==grt)
    {
        return arr[indx];
    }
    else if(indx>grt)
    {
        return quick(arr,grt+1,r);
    }
    return quick(arr,l,grt-1);
}
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) 
    {
        indx=k-1;
        return quick(arr,l,r);
    }
};
