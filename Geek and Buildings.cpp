#define ll long long

ll int dp[100005];
class Solution{
    public:
    long long maximum_energy(int n, vector<int> &heights)
    {
        //dp[i] denotes maximum energy from i
        
        dp[n]=0;
        vector<int>index(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]<=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                index[i]=n;
            }
            else
            {
                index[i]=st.top();
            }
            st.push(i);
            
        }
        ll int ans=0;
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=heights[i]^dp[index[i]];
            ans=max(ans,dp[i]);
        }
        return ans;
        
    }
};
