class Solution 
{
  public:
    int maxIntersections(vector<vector<int>> lines, int N) 
    {
        int n=N;
        map<int,int>mp;
        for(auto x:lines)
        {
            int f=x[0];
            int s=x[1]+1;
            mp[f]++;
            mp[s]--;
        }
        int ans=0;
        int tot=0;
        for(auto x:mp)
        {
            tot=tot+x.second;
            ans=max(ans,tot);
        }
        return ans;
    }
};
