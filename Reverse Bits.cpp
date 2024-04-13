class Solution {
  public:
    long long reversedBits(long long x) {
        #define ll long long
        vector<int>v;
        ll int ans=0;
        for(int i=0;i<32;i++)
        {
            if((x&(1LL<<i)))
            {
                ans|=1LL<<(31-i);
            }
        }
        return ans;
    }
};
