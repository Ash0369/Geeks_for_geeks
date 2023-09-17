#define ll long long
class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<ll int>ans;
        ans.push_back(1);
        if(n>1)
        {
            ans.push_back(1);
        }
        n=n-2;
        ll int last=1;
        while(n>0)
        {
            ll int z=ans.back();
            ans.push_back(z+last);
            last=z;
            n--;
        }
        return ans;
    }
};
