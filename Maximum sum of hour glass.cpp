class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        
        int ans=-1;
        
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<m-2;j++)
            {
                int p=0;
                
                p+=mat[i][j]+mat[i][j+1]+mat[i][j+2];
                p+=mat[i+1][j+1];
                p+=mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2];
                
                ans=max(ans,p);
            }
        }
        return ans;
    }
};
