class Solution 
{
  public:
    vector<int> minQuery(int n, int p, vector<int> &vec, vector<vector<int>> &q) 
    {
        #define ll long long
        vector<vector<int>>dp(n,vector<int>(40,0));
        
        for(int i=0;i<n;i++)
        {
            int ele=vec[i];
            
            for(int j=0;j<=30;j++)
            {
                if((ele&(1<<j)))
                {
                    dp[i][j]++;
                }
                if(i>0)
                {
                    dp[i][j]+=dp[i-1][j];
                }
            }
        }
        
        vector<int>ans;
        
        for(auto x:q)
        {
            int l1=x[0];
            int r1=x[1];
            
            int l2=x[2];
            int r2=x[3];
            
            l1--;
            r1--;l2--;
            r2--;
            
            
            int z=r1-l1+1;
            int temp=0;
            for(int j=0;j<=30;j++)
            {
                int cnt=dp[r1][j];
                if(l1>0)
                {
                    cnt-=dp[l1-1][j];
                }
                if(cnt==z)
                {
                    temp=temp|(1<<j);
                }
            }
            
            int z2=r2-l2+1;
            int temp2=0;
            for(int j=0;j<=30;j++)
            {
                int cnt=dp[r2][j];
                if(l2>0)
                {
                    cnt-=dp[l2-1][j];
                }
                if(cnt==z2)
                {
                    temp2=temp2|(1<<j);
                }
            }
            ans.push_back(temp|temp2);
        }
        return ans;
    }
};
