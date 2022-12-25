int count1(int n,int m,vector<vector<int>>&grid)
{
    int cnt=0;
    
    for(int i=0;i<n;i++)
    {
        int one=0;
        int zero=0;
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        cnt+=max(one,zero);
    }
    return cnt;
}
int ans=0;
void calc(int n,int m,vector<vector<int>>&grid,int curr)
{
    if(curr==m)
    {
        ans=max(ans,count1(n,m,grid));
        return;
    }
    ans=max(ans,count1(n,m,grid));
    calc(n,m,grid,curr+1);
    
    //Fliping curr column
    
    for(int i=0;i<n;i++)
    {
        if(grid[i][curr]==0)
        {
            grid[i][curr]=1;
        }
        else
        {
            grid[i][curr]=0;
        }
    }
    calc(n,m,grid,curr+1);
}
class Solution 
{
  public:
    int optimalMoves(int n,int m, vector<vector<int>>grid) 
    {
        ans=0;
        calc(n,m,grid,0);
        return ans;
    }
};
