//Method-1 : BFS


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


//Method-2 : DFS


#define mp(a,b) make_pair(a,b)

void dfs(int x,int y,int fixedx,int fixedy,vector<pair<int,int>>&vec,vector<vector<bool>>&vis,vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vec.push_back({fixedx-x,fixedy-y});
    
    vis[x][y]=true;
    
     vector<int>dx={-1,0,1,0};
     vector<int>dy={0,1,0,-1};
     
     for(int j=0;j<4;j++)
     {
         int nx=x+dx[j];
         int ny=y+dy[j];
         
         if(nx>=0 && nx<n && ny>=0 && ny<m)
         {
             if(vis[nx][ny]==false && grid[nx][ny]==1)
             {
                 dfs(nx,ny,fixedx,fixedy,vec,vis,grid);
             }
         }
     }
}
class Solution 
{
  public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
       
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==false)
                {
                   
                    vector<pair<int,int>>vec;
                    
                    dfs(i,j,i,j,vec,vis,grid);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};
