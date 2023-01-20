class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      int n=N;
      vector<int>weight(n,0);
      for(int i=0;i<n;i++)
      {
          if(Edge[i]!=-1)
          {
              weight[Edge[i]]+=i;
          }
      }
      int ans=0;
      int cell=0;
      for(int i=0;i<n;i++)
      {
          if(weight[i]>=ans)
          {
              ans=weight[i];
              cell=i;
          }
      }
      return cell;
  }
};
