#define ll long long
int max_sum(int a[],int n)
{
    ll int sum=0;
    ll int ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        ans+=i*a[i];
    }
    ll int c=ans;
    for(int i=n-1;i>=0;i--)
    {
        c+=sum;
        c-=n*a[i];
        ans=max(ans,c);
    }
    return ans;
    
}
