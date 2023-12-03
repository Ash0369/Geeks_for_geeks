class Solution{
    public:
    int solve(string s, int K){
        int k=K;
        int n=s.size();
        vector<int>dp(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                ans++;
                dp[i]=1;
                int av=k;
                int j=i-1;
                while(j>=0 && av>0 && dp[j]==0)
                {
                    dp[j]=1;
                    ans++;
                    j--;
                    av--;
                }
                av=k;
                j=i+1;
                while(j<n && s[j]=='0' && av>0 && dp[j]==0)
                {
                    dp[j]=1;
                    ans++;
                    j++;
                    av--;
                }
            }
        }
        return ans;
    }
};
