set<int>p={2,3,5,7,11,13,17,19};
class Solution {
  public:
    vector<int> findBots(vector<string> &usernames, int n) 
    {
        vector<int>ans;
        for(auto x:usernames)
        {
            set<char>st;
            for(int i=0;i<x.size();i=i+2)
            {
                st.insert(x[i]);
            }
            int sz=st.size();
            //cout<<sz<<endl;
            if(p.find(sz)==p.end())
            {
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
            }
        }
        return ans;
    }
};
