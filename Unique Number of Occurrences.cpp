class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        set<int>st;
        int num=0;
        for(auto x:mp)
        {
            num++;
            st.insert(x.second);
        }
        return st.size()==num;
    }
};
