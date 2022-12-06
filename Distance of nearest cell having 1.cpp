class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<vector<int>>ans=grid;
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	            else
	            {
	                ans[i][j]=INT_MAX;
	            }
	        }
	    }
	    int dx[4]={-1,0,1,0};
	    int dy[4]={0,1,0,-1};
	    int dist=0;
	    while(!q.empty())
	    {
	        dist++;
	        int sz=q.size();
	        for(int i=0;i<sz;i++)
	        {
	            int x=q.front().first;
	            int y=q.front().second;
	            q.pop();
	            for(int j=0;j<4;j++)
	            {
	                int nx=x+dx[j];
	                int ny=y+dy[j];
	                
	                if(nx>=0 && ny>=0 && nx<n && ny<m && dist<ans[nx][ny])
	                {
	                    ans[nx][ny]=dist;
	                    q.push({nx,ny});
	                }
	            }
	        }
	    }
	    
	    return ans;
	}
};
