class Solution
{
public:
    vector<int> recamanSequence(int n)
    {
        set<int>st;
        vector<int>ans;
        ans.push_back(0);
        st.insert(0);
        
        for(int i=1;i<n;i++)
        {
            if(ans.back()-i>0 && st.find(ans.back()-i)==st.end())
            {
                ans.push_back(ans.back()-i);
                st.insert(ans.back());
            }
            else{
                ans.push_back(ans.back()+i);
                st.insert(ans.back());
            }
        }
        return ans;
    }
};
