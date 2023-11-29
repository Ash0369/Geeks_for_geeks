class Solution 
{
  public:
    int minCostPath(int N, int M, vector<vector<int>> &vec) 
    {
        int n=N;
        int m=M;
        vector<vector<int>>data;
        vector<int>cnt(m+1,0);
        int u=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                data.push_back({vec[i][j],j});
            }
        }
        
        sort(data.begin(),data.end());
        
        int left=0;
        int ans=1e9;
        for(int i=0;i<(n*m);i++)
        {
            int col=data[i][1];
            cnt[col]++;
            if(cnt[col]==1)
            {
                u++;
            }
            
            while(u==m)
            {
                ans=min(ans,data[i][0]-data[left][0]);
                cnt[data[left][1]]--;
                if(cnt[data[left][1]]==0)
                {
                    u--;
                }
                left++;
            }
        }
        return ans;
    }
};
