void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int partition(int arr[], int low, int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    do
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
    
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }while(i<j);
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int partion_index;
        partion_index=partition(arr,low,high);
        quickSort(arr,low,partion_index-1);
        quickSort(arr,partion_index+1,high);
    }
}
