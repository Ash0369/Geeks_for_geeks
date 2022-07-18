void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void selectionSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int j=i;
        int k=i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[k])
            {
                k=j;
            }
        }
        swap(arr[i],arr[k]);
    }
}
