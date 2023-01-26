class Solution 
{
public:
    string customSortString(string order, string s) 
    {
        map<char,int>mp;
        for(auto x:s)
            mp[x]++;
        
        string ans="";
        for(auto x:order)
        {
            for(int i=0;i<mp[x];i++)
            {
                ans.push_back(x);
            }
            mp[x]=0;
        }
        for(auto x:mp)
        {
            for(int i=0;i<x.second;i++)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
