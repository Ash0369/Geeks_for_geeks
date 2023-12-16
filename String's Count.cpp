#define ll long long
long long int countStr(long long int n)
{
    if(n==1)
    {
        return 3;
    }
    if(n==2)
    {
        return 8;
    }
    ll int ans=1;
    ans+=n;
    ans+=(n*(n-1));
    ans+=(n*(n-1)*(n-2))/2;
    ans+=n;
    ans+=n*(n-1)/2;
    return ans;
}
