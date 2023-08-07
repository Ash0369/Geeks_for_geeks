#define ll long long
class Solution
{
public:
    long long int countStrings(string s)
    {
        map<int,int>mp;
        for(auto x:s)
        {
            mp[x-'a']++;
        }
        ll int ans=0;
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                if(mp[i]==0 || mp[j]==0)
                {
                    continue;
                }
                ll int a=mp[i];
                ll int b=mp[j];
                
                //ac1  * bc1
                
                ans+=a*b;
            }
        }
        return ans+1;
    }
};
