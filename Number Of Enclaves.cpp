class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1 && (i==0 || j==0 || i==n-1 || j==m-1))
                {
                    
                    dp[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==1 && dp[nx][ny]==0)
                    {
                        dp[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
                
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]==0 && mat[i][j]==1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
