class Solution {
  public:
    int collectingCoins(int c, vector<vector<int>> &coins) 
    {
        map<int,int>h;
        map<int,int>v;
        map<int,int>da;
        map<int,int>db;
        
        int ans=0;
        
        for(auto x:coins)
        {
            int a=x[0];
            int b=x[1];
            
            h[a]++;
            v[b]++;
            
            da[a+b]++;
            
            db[a-b]++;
            
            ans=max(h[a],ans);
            ans=max(ans,v[b]);
            
            ans=max(ans,da[a+b]);
            ans=max(ans,db[a-b]);
        }
        return ans;
    }
};
