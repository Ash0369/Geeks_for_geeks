class Solution
{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c)
    {
        queue<pair<int,int>>q;
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='W')
                {
                    dp[i][j]=0;
                    //cout<<i<<" "<<j<<endl;
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
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && dp[nx][ny]>1+dp[x][y] && c[nx][ny]!='N')
                    {
                        dp[nx][ny]=1+dp[x][y];
                        q.push({nx,ny});
                    }
                }
                
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]!='H')
                {
                    dp[i][j]=0;
                }
                if(dp[i][j]==INT_MAX)
                {
                    dp[i][j]=-1;
                }
                else
                {
                    dp[i][j]=2*dp[i][j];
                }
            }
        }
        
        return dp;
    }
};
