class Solution {
  public:
    int candyShop(int n, vector<int> &candies) {
        map<int,int>mp;
        for(auto x:candies)
        {
            mp[x]++;
        }
        int ans=0;
        for(auto x:mp)
        {
            ans+=x.first;
        }
        return ans;
    }
};
