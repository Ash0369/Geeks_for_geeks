int dy[8]={0,1,1,1,0,-1,-1,-1};
int dx[8]={1,1,0,-1,-1,-1,0,1};

int n,m;
bool dfs(int x,int y,int index,string &s,vector<vector<char>>&grid,vector<vector<int>>&dp,int dir)
{
    
    if(grid[x][y]!=s[index]) return false;
    
    if(index==s.size()-1) return true;
    dp[x][y]=1;
    bool res=false;
    if(dir!=-1)
    {
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(nx>=0 && ny>=0 && nx<n && ny<m && dp[nx][ny]==0)
        {
            
            res=dfs(nx,ny,index+1,s,grid,dp,dir);
        }
        dp[x][y]=0;
        return res;
    }
    
    bool ans=false;
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m && dp[nx][ny]==0)
        {
            ans=ans|dfs(nx,ny,index+1,s,grid,dp,i);
        }
    }
    dp[x][y]=0;
    return ans;
}
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    n=grid.size();
	    m=grid[0].size();
	    vector<vector<int>>ans;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            vector<vector<int>>dp(n,vector<int>(m,0));
	            if(dfs(i,j,0,word,grid,dp,-1))
	           {
	               ans.push_back({i,j});
	           }
	        }
	    }
	    return ans;
	}
};
