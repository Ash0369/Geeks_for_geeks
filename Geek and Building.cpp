#define ll long long
class Solution
{
    public:
    long long maximum_energy(int n, vector<int> &heights)
    {
        vector<ll int>dp(n+10,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=heights[i];
            while(!st.empty() && heights[st.top()]<=heights[i])
            {
                st.pop();
            }
            if(st.size()>0)
            {
                dp[i]=dp[i]^(dp[st.top()]);
            }
            st.push(i);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
