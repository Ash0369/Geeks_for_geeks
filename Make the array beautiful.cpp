#define ll long long
class Solution 
{
  public:
    vector<int> makeBeautiful(vector<int> arr) 
    {
        vector<int>ans;
        int n=arr.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            ll int ele=arr[i];
            if(!st.empty() && (1LL*st.top()*ele)<0)
            {
                st.pop();
                continue;
            }
            else if(!st.empty() && ((st.top()==0 && ele<0 ) ||(st.top()<0 && ele==0)))
            {
                st.pop();
                continue;
            }
            st.push(ele);
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
