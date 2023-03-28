#define ll long long
ll int ans=0;
ll int buy(int right,Shop shop,ll int k)
{
    int left=0;
    int index=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        ll int val=shop.get(mid);
        if(val>k)
        {
            right=mid-1;
        }
        else if(val<=k)
        {
            ans=val;
            index=mid;
            left=mid+1;
        }
    }
    return index;
}
class Solution{
    public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k)
    {
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'
        ll int ans=0;
        int right=n-1;
        while(true)
        {
            right=buy(right,shop,k);
            if(right==-1)
            {
                return ans;
            }
            ll int price=shop.get(right);
            ans+=(k/price);
            k=k%price;
        }
        return 0;
    }

};
