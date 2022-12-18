#define ll long long
bool check(ll int val,ll int k)
{
    if(k>=val)
    {
        return true;
    }
    return false;
}
class Solution
{
    public:
    Shop sp; 
    Solution(Shop shop)
    {
        sp=shop;
        // Constructor
    }
    long long find(int n, long k)
    {
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        //Shop shop;
        ll int ans=0;
        int left=0;
        int right=n-1;
        while(k>0)
        {
            left=0;
            //No need to reset right as it will be always where we can afford max
            ll int can=0;
            ll int price=0;
            while(left<=right)
            {
                int mid=(left+right)/2;
                ll int val=sp.get(mid);
                
                
                if(check(val,k))
                {
                    can=(k/val);
                    price=val;
                    left=mid+1;
                }
                else
                {
                    right=mid-1;
                }
            }
            if(can==0)
            {
                break;
            }
            ans=ans+can;
            k=k-(can*price);
        }
        return ans;
    }
};
