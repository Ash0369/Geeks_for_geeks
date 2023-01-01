class Solution 
{
  public:
    string solve(int N, string S) 
    {
        string s=S;
        int n=N;
        
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        int mx=0;
        string ans="";
        
        for(auto x:mp)
        {
            if(x.second>mx)
            {
                mx=x.second;
                ans.clear();
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
