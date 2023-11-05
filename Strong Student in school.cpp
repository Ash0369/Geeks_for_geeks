
int diffSum(int n,int m,int arr[])
{
    sort(arr,arr+n);
    #define ll long long
    
    long long int tot=0;
    int z=m;
    for(int i=n-1;i>=0;i--)
    {
        if(z==0)
        {
            break;
        }
        tot=tot+arr[i];
        tot=tot-arr[n-i-1];
        z--;
        if(z==0)
        {
            break;
        }
    }
    return tot;
    
}
