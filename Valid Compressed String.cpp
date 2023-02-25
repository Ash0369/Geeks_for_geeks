class Solution 
{
  public:
    int checkCompressed(string S, string T) 
    {
        string s=S;
        string t=T;
        
        int n=t.size();
        int m=s.size();
        int p=0;
        int i=0;
        while(i<n)
        {
            if(p>=m)
            {
                return 0;
            }
            int  c=int(t[i]);
            if(c>=65 && c<=90)
            {
                if(s[p]!=t[i])
                {
                    return 0;
                }
                p++;
                i++;
            }
            else
            {
                int todel=0;
                while(i<n && isdigit(t[i]))
                {
                    todel=(todel*10)+t[i]-'0';
                    i++;
                }
                p=p+todel;
            }
            
        }
        if(p!=m || i!=n)
        {
            return 0;
        }
        return 1;
    }
};
