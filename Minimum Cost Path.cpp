int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

#define pii pair<int,pair<int,int>>
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
        
        priority_queue<pii,vector<pii>,greater<pii>>q;
        
        q.push({grid[0][0],{0,0}});
        dp[0][0]=grid[0][0];
        while(!q.empty())
        {
            int cost=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<n && dp[nx][ny]>(dp[x][y]+grid[nx][ny]))
                {
                    dp[nx][ny]=dp[x][y]+grid[nx][ny];
                    q.push({dp[nx][ny],{nx,ny}});
                }
            }
        }
        return dp[n-1][n-1];
    }
};
