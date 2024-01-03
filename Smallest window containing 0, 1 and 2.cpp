class Solution 
{
  public:
    int smallestSubstring(string s) 
    {
        int n=s.size();
        
        int left=0;
        
        int right=0;
        
        int z=0;
        int o=0;
        int t=0;
        
        int ans=n+10;
        while(right<n)
        {
            if(s[right]=='0')
            {
                z++;
            }
            if(s[right]=='1')
            {
                o++;
            }
            if(s[right]=='2')
            {
                t++;
            }
            while(z>0 && o>0 && t>0)
            {
                ans=min(ans,right-left+1);
                if(s[left]=='0')
                {
                    z--;
                }
                if(s[left]=='1')
                {
                    o--;
                }
                if(s[left]=='2')
                {
                    t--;
                }
                left++;
            }
            right++;
        }
        if(ans>n)
        {
            ans=-1;
        }
        return ans;
    }
};
