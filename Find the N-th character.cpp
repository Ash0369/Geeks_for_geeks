class Solution
{
  public:
    char nthCharacter(string s, int r, int n) 
    {
        int sz=s.size();
        int d=sz/2;
        d++;
        
        while(r--)
        {
            string g="";
            for(int i=0;i<d;i++)
            {
                if(s[i]=='1')
                {
                    g.push_back('1');
                    g.push_back('0');
                }
                else
                {
                    g.push_back('0');
                    g.push_back('1');
                }
            }
            s=g;
        }
        
        return s[n];
    }
};
