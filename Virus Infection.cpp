class Solution
{
    public:
    int solve(string s, int K)
    {
        int k=K;
        int n=s.length();
        int ans=0;
        vector<bool>dp(n,false);
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                q.push({i,0});
                ans++;
                dp[i]=true;
            }
        }
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if(node.second<k)
            {
                int nxt=node.first-1;
                if(nxt>=0 && dp[nxt]==false)
                {
                    ans++;
                    dp[nxt]=true;
                    q.push({nxt,node.second+1});
                }
                nxt=node.first+1;
                if(nxt<n && dp[nxt]==false)
                {
                    ans++;
                    dp[nxt]=true;
                    q.push({nxt,node.second+1});
                }
            }
        }
        return ans;
    }
};
