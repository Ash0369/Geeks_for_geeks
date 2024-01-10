class Solution{
    public:
    int minOPs(int n, vector<int> &A)
    {
        map<int,int>mp;
        int mx=0;
        for(auto x:A)
        {
            mp[x]++;
            mx=max(mx,mp[x]);
        }
        vector<int>v;
        for(auto x:mp)
        {
            v.push_back(x.second);
        }
        sort(v.begin(),v.end());
        v.pop_back();
        int ans=0;
        while(mx<=(n/2))
        {
            mx=mx+v.back();
            v.pop_back();
            ans++;
        }
        return ans;
    }
};
