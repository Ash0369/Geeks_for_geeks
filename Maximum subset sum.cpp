#define ll long long

ll int dp[100005][2];
ll int dfs(int index,int prev,vector<int>&vec)
{
    if(index>=vec.size())
    {
        return 0;
    }
    if(dp[index][prev]!=-1)
    {
        return dp[index][prev];
    }
    ll int ans1=dfs(index+1,1,vec)+vec[index];
    
    if(prev==0)
    {
         return dp[index][prev]=ans1;
    }
    ll int ans2=dfs(index+1,0,vec);
    return dp[index][prev]=max(ans1,ans2);
}
class Solution 
{

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) 
    {
        int n=N;
        vector<int>vec=A;
        if(n==1)
        {
            return vec[0];
        }
        memset(dp,-1,sizeof(dp));
        return dfs(0,1,vec);
    }
};
