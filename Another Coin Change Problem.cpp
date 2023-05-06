int dp[101][1001];
bool check(int index,int n, int k, int target, vector<int> &coins)
{
    if(target==0 && k==0)
    {
        return true;
    }
    if(index==n-1)
    {
        if(target%coins[n-1]==0 && target/coins[n-1]==k)
        {
            return true;
        }
        return false;
    }
    if(dp[k][target]!=-1)
    {
        return dp[k][target];
    }
    bool a=check(index+1,n,k,target,coins);
    bool b=false;
    if(target-coins[index]>=0 && k>=1)
    {
        b=check(index,n,k-1,target-coins[index],coins);
    }
    return dp[k][target]=a|b;
}
class Solution 
{
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) 
    {
        memset(dp,-1,sizeof(dp));
        return check(0,N,K,target,coins);
    }
};
