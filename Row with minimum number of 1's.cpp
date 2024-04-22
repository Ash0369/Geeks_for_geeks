class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int ans=0;
        int r=m+10;
        
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]){
                    c++;
                }
            }
            if(c<r)
            {
                r=c;
                ans=i;
            }
        }
        return ans+1;
        
        
    }
};
