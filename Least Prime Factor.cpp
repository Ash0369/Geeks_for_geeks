vector<int> pre(int n)
{
    vector<int>dp(n+5,0);
    dp[1]=1;//dp[i] denotes lpf of i
    
    for(int i=2;i<=n;i++)
    {
        if(dp[i]!=0)
        {
            continue;
        }
        dp[i]=i;
        for(int j=2*i;j<=n;j=j+i)
        {
            if(dp[j]!=0)
            {
                continue;
            }
            dp[j]=i;
        }
    }
    return dp;
}
class Solution 
{
  public:
    vector<int> leastPrimeFactor(int n) 
    {
        vector<int>dp=pre(n);
        vector<int>ans;
        ans.push_back(0);
        //cout<<dp[1]<<endl;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(dp[i]);
        }
        return ans;
    }
};
