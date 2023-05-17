class Solution
{
public:
    int isPossible(int n, int m, string s)
    {
        int l=0;
        int u=0;
        int xmin=0;
        int xmax=0;
        int ymin=0;
        int ymax=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='L')
            {
                l++;
            }
            else if(s[i]=='R')
            {
                l--;
            }
            else if(s[i]=='U')
            {
                u++;
            }
            else
            {
                u--;
            }
            xmin=min(xmin,l);
            xmax=max(xmax,l);
            ymin=min(ymin,u);
            ymax=max(ymax,u);
            
        }
        if(xmax-xmin>=m || ymax-ymin>=n)
        {
            return 0;
        }
        return 1;
    }
};
