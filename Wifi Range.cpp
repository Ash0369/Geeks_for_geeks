class Solution
{
    public:
    bool wifiRange(int N, string S, int X)
    {
        int n=N;
        int x=X;
        string s=S;
        string a=s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                continue;
            }
            for(int j=i-x;j<=i+x;j++)
            {
                if(j<0 || j>=n)
                {
                    continue;
                }
                a[j]='1';
            }
           
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]=='0')
            {
                return false;
            }
        }
        return true;
    }
};
