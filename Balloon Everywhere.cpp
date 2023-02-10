class Solution
{
public:
    int maxInstance(string s)
    {
        map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        int ans=INT_MAX;
        string target="ban";
        for(int i=0;i<target.size();i++)
        {
            ans=min(ans,mp[target[i]]);
        }
        int need=mp['l']/2;
        need=min(need,mp['o']/2);
        
        ans=min(ans,need);
        return ans;
    }
};
