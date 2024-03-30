class Solution {
  public:
    vector<int> BeautifulBits(int n, vector<int> &arr, int q,
                              vector<vector<int>> &queries) 
    {
        vector<vector<int>>dp(n+1,vector<int>(30,0));
        
        for(int i=0;i<n;i++)
        {
            int ele=arr[i];
            for(int j=0;j<30;j++)
            {
                if((ele&(1<<j)))
                {
                    dp[i][j]=1;
                }
                if(i>0)
                {
                    dp[i][j]+=dp[i-1][j];
                }
            }
        }
        
        vector<int>ans;
        
        for(auto x:queries)
        {
            int l=x[0];
            int r=x[1];
            
            l--;
            r--;
            
            int len=r-l+1;
            
            int z=0;
            for(int i=0;i<30;i++)
            {
                int v=dp[r][i];
                if(l>0)
                {
                    v-=dp[l-1][i];
                }
                
                if(v>0)
                {
                    z=z|(1<<i);
                }
            }
            ans.push_back(z);
        }
        return ans;
    }
};
