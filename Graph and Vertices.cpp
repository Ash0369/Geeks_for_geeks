class Solution {
  public:
    long long count(int n)
    {
        n=n*(n-1)/2;
        return 1LL<<n;
    }
};
