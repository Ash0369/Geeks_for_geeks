class Solution 
{
  public:
    #define pii pair<int,pair<int,int>>
    int possiblePath(int n, int m, vector<vector<int>> &grid) 
    {
        queue<pii>q;
        q.push({grid[0][0],{0,0}});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        if(n==1 && m==1)
        {
            return 0;
        }
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
        {
            return -1;
        }
        int move=0;
        //vector<vector<bool>>vis(n+1,vector<int>(m+1,false))
        while(!q.empty())
        {
            int sz=q.size();
            move++;
            for(int j=0;j<sz;j++)
            {
                auto node=q.front();
                q.pop();
                int x=node.second.first;
                int y=node.second.second;
                int type=node.first;
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && (grid[nx][ny]==0 || grid[nx][ny]==2))
                    {
                        if(nx==n-1 && ny==m-1)
                        {
                            return move;
                        }
                        q.push({grid[nx][ny],{nx,ny}});
                        grid[nx][ny]=-1;
                    }
                    else if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && type==2)
                    {
                        if(nx==n-1 && ny==m-1)
                        {
                            return move;
                        }
                        q.push({grid[nx][ny],{nx,ny}});
                        grid[nx][ny]=-1;
                    }
                }
            }
        }
        
        return -1;
    }
};
