class Solution {
  public:
    int maximumBattalions(int n, vector<string> &names) {
        map<string,vector<int>>mp;
        int i=0;
        for(auto x:names)
        {
            mp[x].push_back(i);
            i++;
        }
        
        int ans=0;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            if(mp[names[i]].back()==i)
            {
                last=max(last,i);
            }
            else{
                last=max(last,mp[names[i]].back());
            }
            if(last==i)
            {
                ans++;
            }
        }
        return ans;
        
    }
};
