#define ll long long
class Solution
{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr)
  {
      vector<long long int>ans;
      ll int intial=1LL*n*n;
      
      vector<int>row(n,0);
      vector<int>col(n,0);
      int rm=0;
      int cm=0;
      for(int i=0;i<k;i++)
      {
          int r=arr[i][0]-1;
          int c=arr[i][1]-1;
          
          ll int a=0;
          if(row[r]==0)
          {
              a=a+n-cm;
              rm++;
              row[r]=1;
          }
          if(col[c]==0)
          {
              
              a=a+n-rm;
              cm++;
              col[c]=1;
          }
          intial=intial-a;
          ans.push_back(intial);
      }
      return ans;
  }
};
