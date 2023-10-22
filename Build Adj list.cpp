class Solution
{
  public:
  vector<vector<int>> generateAdjacencyList(int V, int E, vector<vector<int>> &edges)
  {
      vector<vector<int>>graph(V);
      vector<set<int>>graph1(V);
      for(auto x:edges)
      {
          if(graph1[x[0]].find(x[1])!=graph1[x[0]].end())
          {
              continue;
          }
          else{
              graph[x[0]].push_back(x[1]);
              graph1[x[0]].insert(x[1]);
          }
          if(graph1[x[1]].find(x[0])!=graph1[x[1]].end())
          {
              continue;
          }
          else{
              graph[x[1]].push_back(x[0]);
          }
          graph1[x[0]].insert(x[1]);
          graph1[x[1]].insert(x[0]);
      }
      for(int i=0;i<V;i++)
      {
          sort(graph[i].begin(),graph[i].end());
      }
      return graph;
  }
};
