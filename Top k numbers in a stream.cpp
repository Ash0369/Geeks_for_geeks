class Solution 
{
  public:
    vector<vector<int>> kTop(vector<int>& arr, int n, int k) 
    {
        map<int,int>mp;
        set<vector<int>>st;
        vector<vector<int>>ans;
        for(auto x:arr)
        {
            
            mp[x]++;
            if(mp[x]!=1)
            {
                st.erase({mp[x]-1,-1*x});
            }
            st.insert({mp[x],-1*x});
            
            int y=k;
            auto it=st.end();
            it--;
            vector<int>v;
            while(y--)
            {
                if(-1*((*it)[1])==0)
                {
                    break;
                }
                v.push_back(-1*((*it)[1]));
                
                if(it==st.begin())
                {
                    break;
                }
                it--;
            }
            
            ans.push_back(v);
        }
        return ans;
    }
};
