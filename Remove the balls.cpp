class Solution 
{
  public:
    int finLength(int N, vector<int> color, vector<int> radius) 
    {
        stack<pair<int,int>>st;
        int n=N;
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && st.top().first==color[i] && st.top().second==radius[i])
            {
                st.pop();
                continue;
            }
            st.push({color[i],radius[i]});
        }
        return st.size();
    }
};
