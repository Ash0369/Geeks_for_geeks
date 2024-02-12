set<int>st;

class Solution 
{
  public:
    vector<int> findBots(vector<string> &usernames, int n) 
    {
        st.insert(2);
        st.insert(3);
        st.insert(5);
        st.insert(7);
        st.insert(11);
        st.insert(13);
        st.insert(17);
        st.insert(19);
        vector<int>vec;
        for(auto x:usernames)
        {
            set<char>f;
            for(int i=0;i<x.size();i=i+2)
            {
                f.insert(x[i]);
            }
            int sz=f.size();
            if(st.find(sz)!=st.end())
            {
                vec.push_back(1);
            }
            else{
                vec.push_back(0);
            }
        }
        return vec;
    }
};
