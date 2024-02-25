class Solution 
{
  public:
    string smallestString(int n, string s) 
    {
        string g=s;
        reverse(g.begin(),g.end());
        
        if(s==g)
        {
            if(n==1)
            {
                return "-1";
            }
            int i=0;
            int j=n-1;
            bool r=false;
            while(i<j)
            {
                if(s[i]!='a')
                {
                    s[i]='a';
                    r=true;
                    break;
                }
                i++;
                j--;
            }
            if(r==false)
            {
                s[n-1]='b';
            }
            return s;
        }
        else
        {
            int i=0;
            int j=n-1;
            bool r=false;
            while(i<j)
            {
                if(s[i]!='a' && s[j]!='a')
                {
                    s[i]='a';
                    r=true;
                    break;
                }
                i++;
                j--;
            }
            return s;
        }
    }
};
