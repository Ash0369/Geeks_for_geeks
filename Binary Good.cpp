#define ll long long
class Solution
{
    public:
    int solve(string str, int n)
    {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='1')
            {
                int cnt=1;
                i++;
                while(i<n && str[i]=='1')
                {
                    cnt++;
                    i++;
                }
                i--;
                mp[cnt]++;
            }
        }
        ll int ans=n;
        for(int i=0;i<=n;i++)
        {
            ll int op=0;
            for(auto x:mp)
            {
                if(x.first==i)
                {
                    continue;
                }
                op+=x.second*abs(i-x.first);
            }
            ans=min(ans,op);
        }
        
        return ans;
    }
};
