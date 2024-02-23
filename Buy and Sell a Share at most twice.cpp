int dp[1000005][5][5];
int dfs(int index,vector<int>&price,int h,int t)
{
    
    if(t==2 || index>=price.size())
    {
        return dp[index][h][t]=0;
    }
    if(dp[index][h][t]!=-1)
    {
        return dp[index][h][t];
    }

    int a=dfs(index+1,price,h,t);
    if(h==0)
    {
        return dp[index][h][t]=max(a,dfs(index+1,price,1,t)-price[index]);
    }
   
    return dp[index][h][t]=max(a,price[index]+dfs(index+1,price,0,t+1));
    
}
class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price)
        {
            
            for(int i=0;i<price.size();i++)
            {
                for(int j=0;j<=3;j++)
                {
                    for(int k=0;k<=3;k++)
                    {
                        dp[i][j][k]=-1;
                    }
                }
            }
            return dfs(0,price,0,0);
        }
};
