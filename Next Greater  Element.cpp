#define ll long long
class Solution 
{
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n)
    {
        vector<ll int>ans(n);
        stack<pair<ll int,int>>st;
        for(int i=0;i<n;i++)
        {
            ll int x=arr[i];
            while(!st.empty() && x>st.top().first)
            {
                auto ele=st.top();
                st.pop();
                ans[ele.second]=x;
            }
            st.push({x,i});
        }
        while(!st.empty())
        {
            auto ele=st.top();
            st.pop();
            ans[ele.second]=-1;
        }
        return ans;
        
    }
};
