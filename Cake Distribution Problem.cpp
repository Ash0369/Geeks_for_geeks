#define ll long long

bool check(ll int mid,vector<int>& sweetness,int n,int k)
{
    if(mid==0)
    {
        return true;
    }
    ll int curr=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        curr=curr+sweetness[i];
        if(curr>=mid)
        {
            cnt++;
            curr=0;
        }
    }
    return cnt>=(k+1);
}
class Solution
{
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) 
    {
        ll int left=0;
        ll int right=accumulate(sweetness.begin(),sweetness.end(),0LL);
        ll int ans=0;
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            if(check(mid,sweetness,N,K))
            {
                ans=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return ans;
    }
};
