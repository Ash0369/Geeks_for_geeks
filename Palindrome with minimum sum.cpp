class Solution {
  public:
    int minimumSum(string s) 
    {
        int n=s.size();
        int ans=0;
        char pev='-1';
        for(int i=0;i<=n/2;i++)
        {
            if(s[i]!='?')
            {
                
                pev=s[i];
                break;
            }
            else if(s[n-1-i]!='?')
            {
                
                pev=s[n-1-i];
                break;
            }
        }
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!='?' && s[n-1-i]!='?' && s[i]!=s[n-1-i])
            {
                return -1;
            }
            else if(s[i]!='?' && s[n-1-i]=='?')
            {
                s[n-1-i]=s[i];
            }
            else if(s[i]=='?' && s[n-1-i]!='?')
            {
                s[i]=s[n-1-i];
            }
            else if(s[i]!='?' && s[n-1-i]!='?' && s[i]==s[n-1-i])
            {
                continue;
            }
            else
            {
                if(i-1>=0)
                {
                    s[i]=s[i-1];
                    s[n-1-i]=s[i];
                }
                else
                {
                    if(pev=='-1')
                    {
                         s[i]='a';
                         s[n-1-i]=s[i];
                    }
                    else
                    {
                         s[i]=pev;
                         s[n-1-i]=s[i];
                    }
                }
            }
        }
        if(n%2!=0)
        {
            s[n/2]=s[(n/2)-1];
        }
        for(int i=1;i<n;i++)
        {
            ans+=abs(int(s[i])-int(s[i-1]));
        }
        return ans;
    }
};
