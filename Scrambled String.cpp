map<string,bool>mp;
bool compare(string s1,string s2)
{
    if(s1==s2)
    {
        return true;
    }
    int n=s1.size();
    string data=s1+"_"+s2;
    if(mp.find(data)!=mp.end())
    {
        return mp[data];
    }
    for(int i=1;i<n;i++)
    {
        if(compare(s1.substr(0,i),s2.substr(0,i)) && compare(s1.substr(i,n-i),s2.substr(i,n-i)))
        {
            mp[data]=true;
            return true;
        }
        
        if(compare(s1.substr(0,i),s2.substr(n-i,i)) && compare(s1.substr(i,n-i),s2.substr(0,n-i)))
        {
            mp[data]=true;
            return true;
        }
    }
    mp[data]=false;
    return false;
}
class Solution
{
    public:
    bool isScramble(string S1, string S2)
    {
        string s1=S1;
        string s2=S2;
        return compare(s1,s2);
    }    
};
