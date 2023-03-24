class Solution 
{
  public:
    string removeReverse(string S) 
    {
        string s=S;
        int n=s.size();
        map<char,int>mp;
        for(auto x:s)
        {
            mp[x]++;
        }
        int l=0;
        int r=n-1;
        int left=0;
        int right=r;
        int d=1;
        while(l<r)
        {
            if(left<0 || left==n)
            {
                break;
            }
            if(mp[s[left]]>1 && s[left]!='*')
            {
                mp[s[left]]--;
                s[left]='*';
                while(r>=0 && s[r]=='*')
                {
                    r--;
                }
                while(l<n && s[l]=='*')
                {
                    l++;
                }
                if(right==r)
                {
                    left=r;
                    right=l;
                }
                else
                {
                    left=l;
                    right=r;
                }
                d=d*(-1);
                
               
            }
            else
            {
                left=left+d;
            }
        }
        string ans;
        for(int i=l;i<=r;i++)
        {
            if(s[i]!='*')
            {
                ans.push_back(s[i]);
            }
        }
        if(d==-1)
        {
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};
