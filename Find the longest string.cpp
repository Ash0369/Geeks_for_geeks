bool cmp(string &s1,string &s2)
{
    if(s1.length()<s2.length())
    {
        return true;
    }
    else if(s1.length()==s2.length())
    {
        if(s1>s2)
        {
            return true;
        }
    }
    return false;
}
class Solution
{
public:
    string longestString(vector<string> &words)
    {
        map<string,int>mp;
        for(auto x:words)
        {
            mp[x]++;
        }
        sort(words.begin(),words.end(),cmp);
        string ans="";
        for(auto x:words)
        {
            string temp="";
            bool res=true;
            for(int i=0;i<x.length();i++)
            {
                temp.push_back(x[i]);
                if(mp.find(temp)==mp.end())
                {
                    res=false;
                    break;
                }
            }
            if(res)
            {
                ans=temp;
            }
        }
        return ans;
    }
};
