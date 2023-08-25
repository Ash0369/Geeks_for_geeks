class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        map<char,int>mp;
        int ans=-1;
        
        int left=0;
        int u=0;
        for(int right=0;right<s.size();right++)
        {
            mp[s[right]]++;
            if(mp[s[right]]==1)
            {
                u++;
            }
            while(u>k)
            {
                mp[s[left]]--;
                if(mp[s[left]]==0)
                {
                    u--;
                }
                left++;
            }
            if(u==k)
            {
                ans=max(ans,right-left+1);
            }
        }
        return ans;
    }
};
