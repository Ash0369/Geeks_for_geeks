class Solution 
{
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) 
    {
        queue<pair<int,pair<int,int>>>q;
        q.push({mat[0][0],{0,0}});
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        int cnt=0;
        if(n==1 && m==1 && mat[0][0]==0)
        {
            return 0;
        }
        else if(n==1 && m==1 && mat[0][0]==1 && k>=1)
        {
            return 0;
        }
        int iter=0;
        while(!q.empty())
        {
            
            int sz=q.size();
            cnt++;
            for(int i=0;i<sz;i++)
            {
                iter++;
                int x=q.front().second.first;
                int y=q.front().second.second;
                int wall=q.front().first;
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int nx=x+dx[j];
                    int ny=y+dy[j];
               
                    if(nx>=0 && ny>=0 && nx<n && ny<m && dp[nx][ny]>wall)
                    {
                        int add=0;
                        if(mat[nx][ny]==1)
                        {
                            add=1;
                            //We have to take an add variable , so that we not modify original wall
                            //It is possible when we are exploring all 4paths then we got first wall one.
                            //So it has changed wall no on next j for other nx , ny we need original wall.
                            //Find after debugging 3hr a 17*30 Matrix so keep it always in the mind.
                        }
                        dp[nx][ny]=wall+add;
                        if(wall+add>k)
                        {
                            continue;
                        }
                        q.push({wall+add,{nx,ny}});
                        if(nx==n-1 && ny==m-1)
                        {
                            return cnt;
                        }
                    }
                }
            }
            
        }
        
        return -1;
    }
};
