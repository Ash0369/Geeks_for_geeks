
class Solution {
  public:
    long long countBits(long long N) {
        // code here
        #define ll long long
        ll int ans=0;
        for(int i=1;i<=N;i++)
        {
            ans+=__builtin_popcount(i);
        }
        return ans;
    }
};
