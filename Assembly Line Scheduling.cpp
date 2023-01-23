class Solution
{
  public:
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x)
  {
       #define ll long long
       
       int n=a[0].size();
       ll int dp[n+1][2];
       
       dp[n-1][0]=a[0][n-1]+x[0];
       dp[n-1][1]=a[1][n-1]+x[1];
       
       for(int i=n-2;i>=0;i--)
       {
           for(int j=0;j<=1;j++)
           {
               ll int way1=a[j][i]+dp[i+1][j];
               
               ll int way2=a[j][i]+T[j][i+1]+dp[i+1][!j];
               
               dp[i][j]=min(way1,way2);
               
           }
       }
       return min(dp[0][0]+e[0],dp[0][1]+e[1]);
  }
};
