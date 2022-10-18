#define mp(a,b) make_pair(a,b)
class Solution 
{
  public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==false)
                {
                    q.push(mp(i,j));
                    vector<pair<int,int>>v;
                    while(!q.empty())
                    {
                        int x=q.front().first;
                        int y=q.front().second;
                        v.push_back({x-i,y-j});
                        q.pop();
                        
                        for(int k=0;k<4;k++)
                        {
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx>=0 && nx<n && ny>=0 && ny<m)
                            {
                                if(grid[nx][ny]==1 && vis[nx][ny]==false)
                                {
                                    q.push(mp(nx,ny));
                                    vis[nx][ny]=true;
                                }
                            }
                            
                        }
                    }
                    st.insert(v);
                }
            }
        }
        
        return st.size();
    }
};
