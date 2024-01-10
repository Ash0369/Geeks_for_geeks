class Solution
{
    public:
    vector<int> findAnswer(int n, vector<int> &vec)
    {
        #define ll long long
        set<pair<ll int,int>>st;
        ll int tot=0;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            st.insert({tot,i});
            tot+=vec[i];
            while(st.size()>0 && (*st.begin()).first<tot)
            {
                ans[(*st.begin()).second]=i-((*st.begin()).second)+1;
                st.erase(*st.begin());
            }
        }
        return ans;
    }
};
