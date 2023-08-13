int dfs(vector<int>&dp)
{
    int maxsum=dp[0];
    int curr=0;
    for(auto x:dp)
    {
        curr+=x;
        maxsum=max(maxsum,curr);
        if(curr<0)
        {
            curr=0;
        }
    }
    return maxsum;
}
class Solution 
{
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) 
    {
        int r=R;
        int c=C;
        vector<vector<int>>vec=M;
        
        
        int ans=-1e6;
        for(int start=0;start<c;start++)
        {
            vector<int>dp(r,0);
            
            for(int end=start+1;end<=c;end++)
            {
                //ending at end-1
                for(int j=0;j<r;j++)
                {
                    dp[j]+=vec[j][end-1];
                }
                //now i have sum at dp[j] for jth row
                //we will apply kadanene at dp
                ans=max(ans,dfs(dp));
    
            }
        }
        return ans;
    }
};
