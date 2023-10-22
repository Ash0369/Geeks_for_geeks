class Solution 
{
  public:
    int maximizeFlavors(vector<int>& candies, int k) 
    {
        unordered_map<int,int>mp;
        int n=candies.size();
        int ansl=0;
        int ansr=n-1;
        int ans=0;
        int u=0;
        int left=0;
        unordered_map<int,int>stock;
        int tot=0;
        for(auto x:candies)
        {
            stock[x]++;
            if(stock[x]==1)
            {
                tot++;
            }
        }
        for(int i=0;i<n;i++)
        {
            mp[candies[i]]++;
            stock[candies[i]]--;
            if(stock[candies[i]]==0)
            {
                tot--;
            }
            if(mp[candies[i]]==1)
            {
                u++;
            }
            if((i-left+1)>k)
            {
                mp[candies[left]]--;
                if(mp[candies[left]]==0)
                {
                    u--;
                }
                stock[candies[left]]++;
                if(stock[candies[left]]==1)
                {
                    tot++;
                }
                left++;
                ans=max(ans,tot);
            }
        }
        return ans;
    }
};
