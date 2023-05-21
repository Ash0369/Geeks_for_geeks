int missingNumber(int A[], int N)
{
    int xr=N;
    int c=0;
    for(int i=0;i<N-1;i++)
    {
        c=c^A[i];
        xr=xr^(i+1);
    }
    return c^xr;
}
