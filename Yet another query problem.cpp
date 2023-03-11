class Solution 
{
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) 
    {
        int n=N;
        vector<int>f(n+1,0);
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            for(int j=i+1;j<n;j++)
            {
                if(A[i]==A[j])
                {
                    cnt++;
                }
            }
            f[i]=cnt;
        }
        vector<int>ans;
        for(auto x:Q)
        {
            int l=x[0];
            int r=x[1];
            int k=x[2];
            int cnt=0;
            for(int i=l;i<=r;i++)
            {
                if(f[i]==k)
                {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
