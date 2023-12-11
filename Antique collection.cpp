class Solution 
{
  public:
    int antiqueItems(int n, vector<int> &items, vector<int> &price) 
    {
        vector<int>mp(1005,-1);
        for(int i=0;i<n;i++)
        {
            if(mp[items[i]]==-1)
            {
                mp[items[i]]=price[i];
            }
            else
            {
                mp[items[i]]=min(mp[items[i]],price[i]);
            }
        }
        int ans=0;
        for(auto x:mp)
        {
            if(x==-1)
            {
                continue;
            }
            ans+=x;
        }
        return ans;
    }
};
