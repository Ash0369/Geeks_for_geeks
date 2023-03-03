#define ll long long
class Solution
{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        ll int l=L;
        ll int b=B;
        vector<ll int>vec;
        ll int n=__gcd(l,b);
        vec.push_back((l/n)*(b/n));
        vec.push_back(n);
        return vec;
    }
};
