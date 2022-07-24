pair<long long, long long> getMinMax(long long a[], int n) 
{
    sort(a,a+n);
    return make_pair(a[0],a[n-1]);
}
