bool dfs(int index,string &s,set<string>&st,string &curr)
{
    if(index==s.size())
    {
        return curr.size()==0;
    }
    curr.push_back(s[index]);
    bool a=dfs(index+1,s,st,curr);
    
    
    bool b=false;
    
    if(st.find(curr)!=st.end())
    {
        string g="";
        b=dfs(index+1,s,st,g);
    }
    curr.pop_back();
    return a|b;
}
class Solution
{
public:
    int wordBreak(int n, string &s, vector<string> &word) 
    {
        n=s.size();
        set<string>st;
        for(auto x:word)
        {
            st.insert(x);
        }
        string curr="";
        return dfs(0,s,st,curr);
    }
};
