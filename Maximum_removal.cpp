int ans=0;
int dp[505][505];
vector<int>pi(505,0);
bool dfs(int index,vector<int>&vec,int x)
{
    if(x<0)
    {
        return false;
    }
    if(index==vec.size())
    {
        return x==0;
    }
    if(dp[index][x]!=-1)
    {
        return dp[index][x];
    }
    bool ans1=dfs(index+1,vec,x-vec[index]);
    bool ans2=dfs(index+1,vec,x);
    
    if(ans1==true)
    {
        pi[index]=1;
    }
    return dp[index][x]=ans1|ans2;
}
class Solution 
{
    public:
    int maxRemoval(int N, vector<int> A, int X)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=X;j++)
            {
                dp[i][j]=-1;
            }
            pi[i]=0;
        }
        dfs(0,A,X);
        ans=0;
        for(int i=0;i<N;i++)
        {
            if(pi[i]==0)
            {
                ans++;
            }
        }
        return ans;
    }
};
