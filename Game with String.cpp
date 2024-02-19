class Solution
{
public:
    int minValue(string s, int k)
    {
        map<int,int>mp;
        for(auto x:s)
        {
            mp[x-'a']++;
        }
        
        multiset<int>st;
        for(auto x:mp)
        {
            st.insert(x.second);
        }
        
        while(k--)
        {
            int v=*st.rbegin();
            st.erase(st.find(v));
            v--;
            st.insert(v);
        }
        
        int ans=0;
        
        for(auto x:st)
        {
            if(x>0)
            {
                ans+=x*x;
            }
        }
        return ans;
    }
};
