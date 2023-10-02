class Solution {
  public:
    int solve(int N, string S) {
        map<char,int>mp;
        int n=N;
        int mx=0;
        string s=S;
        char c=s[0];
        for(auto x:s)
        {
            mp[x]++;
            if(mx<mp[x])
            {
                mx=mp[x];
                c=x;
            }
        }
        int ans=0;
        for(auto x:mp)
        {
            if(x.first!=c)
            {
                ans++;
            }
        }
        return ans;
    }
};
