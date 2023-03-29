//Method-1 : 

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

//Method2 : 

class Solution
{
    public:
    int countSubstring(string S)
    {
        int ans=0;
        string s=S;
        int n=s.size();
        map<int,int>mp;
        mp[0]=1;
        int tot=0;
        for(int j=0;j<n;j++)
        {
            if(int(s[j])>=97)
            {
                tot++;
            }
            else
            {
                tot--;
            }
            ans+=mp[tot];
            mp[tot]++;
        }
       
        return ans;
    }
};
