void merge(int arr[],int low,int mid,int high)
{
    int i,j,k;
    int temp[high+1];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    for(;i<=mid;i++)
    {
        temp[k]=arr[i];
        k++;
    }

    for(;j<=high;j++)
    {
        temp[k]=arr[j];
        k++;
    }

    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }
}
void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);

    }
}
