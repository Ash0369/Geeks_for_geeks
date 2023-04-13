#define ll long long

pair<ll int,ll int>check(vector<ll int>&sum,ll int left,ll int right)
{
    int l=left;
    int r=right;
    ll int msum=0;
    ll int mxsum=sum[right]-sum[left-1];
    while(l<=r)
    {
        int mid=(l+r)/2;
        ll int lsum=sum[mid]-sum[left-1];
        ll int rsum=sum[right]-sum[mid];
        
        if(abs(rsum-lsum)<mxsum-msum)
        {
            msum=min(lsum,rsum);
            mxsum=max(lsum,rsum);
        }
        if(lsum<rsum)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return {msum,mxsum};
}
class Solution
{
public:
    long long minDifference(int N, vector<int> &A) 
    {
        int n=N;
        vector<ll int>sum(n+1,0);
        for(int i=0;i<n;i++)
        {
            sum[i+1]=sum[i]+A[i];
        }
        ll int ans=sum[n];
        for(int i=1;i<n-2;i++)
        {
            auto p1=check(sum,1,i+1);
            auto p2=check(sum,i+2,n);
            ans=min(ans,max(p1.second,p2.second)-min(p1.first,p2.first));
        }
        return ans;
    }
};
