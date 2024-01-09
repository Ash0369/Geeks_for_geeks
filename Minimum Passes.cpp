class Solution 
{
  public:
    int minPass(int n, vector<int> &height) 
    {
        int ans=0;
        stack<vector<int>>st;
        st.push({height[n-1],0});
        for(int i=n-2;i>=0;i--)
        {
            if(st.empty())
            {
                st.push({height[i],0});
            }
            else
            {
                int c=0;
                int d=0;
                
                while(!st.empty() && st.top()[0]<height[i])
                {
                    d=st.top()[1];
                    st.pop();
                    c=max(c+1,d);
                }
                ans=max(ans,c);
                st.push({height[i],c});
            }
        }
        return ans;
    }
};
