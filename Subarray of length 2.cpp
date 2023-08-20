#define ll long long
class Solution
{
    public:
    long long maxSum(int N, vector<int> A)
    {
        ll int n=N;
        vector<int>a=A;
        ll int pos=0;
        ll int neg=0;
        ll int tot=0;
        ll int mn=1e9;
        ll int z=0;
        ll int curr=n;
        ll int prev=1;
        for(ll int i=0;i<a.size();i++)
        {
            ll int n1=a.size();
            ll int x=a[i];
            x=1LL*x*((i+1)*(n1-i));
            mn=min(mn,abs(x));
            if(x==0)
            {
                z++;
            }
            else if(x>0)
            {
                pos+=x;
            }
            else
            {
                neg+=abs(x);
                tot++;
            }
            ll int z=curr;
            curr--;
            prev=z;
        }
        
        if(tot%2==0 || z>0)
        {
            ll int tot=0;
            
            return pos+neg;
        }
        else
        {
            return pos+neg-mn-mn;
        }
    }
};
