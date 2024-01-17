vector<vector<int>>ans;
void dfs(int index,int n,vector<int>&arr,vector<int>&dp,vector<int>&vec)
{
    if(index==n)
    {
        ans.push_back(vec);
    }
    set<int>st;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==1)
        {
            continue;
        }
        if(st.find(arr[i])!=st.end())
        {
            continue;
        }
        st.insert(arr[i]);
        dp[i]=1;
        vec.push_back(arr[i]);
        dfs(index+1,n,arr,dp,vec);
        vec.pop_back();
        dp[i]=0;
    }
}
class Solution 
{
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) 
    {
        ans.clear();
        vector<int>dp(n,0);
        vector<int>vec;
        dfs(0,n,arr,dp,vec);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
