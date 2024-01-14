class Solution 
{
  public:
    int candyShop(int n, vector<int> &candies) 
    {
        set<int>st;
        for(auto x:candies)
        {
            st.insert(x);
        }
        int sz=st.size();
        
        int ans=1e9;
        
        map<int,int>mp;
        
        int left=0;
        int d=0;
        int cost=0;
        for(int i=0;i<n;i++)
        {
            mp[candies[i]]++;
            cost+=candies[i];
            if(mp[candies[i]]==1)
            {
                d++;
            }
            while(d==sz)
            {
                ans=min(ans,cost);
                cost-=candies[left];
                mp[candies[left]]--;
                
                if(mp[candies[left]]==0)
                {
                    d--;
                }
                left++;
            }
        }
        return ans;
    }
};
