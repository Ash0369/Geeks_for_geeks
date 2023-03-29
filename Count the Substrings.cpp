class Solution
{
    public:
    int countSubstring(string S)
    {
        int ans=0;
        string s=S;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int u=0;
            int l=0;
            for(int j=i;j<n;j++)
            {
                if(int(s[j])>=97)
                {
                    l++;
                }
                else
                {
                    u++;
                }
                if(l==u)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
