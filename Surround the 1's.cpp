class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    int a=0;
                    if(i-1>=0 && matrix[i-1][j]==0) a++;
                    if(j-1>=0 && matrix[i][j-1]==0) a++;
                    if(i+1<n && matrix[i+1][j]==0) a++;
                    if(j+1<m && matrix[i][j+1]==0) a++;
                    if(j+1<m && i+1<n && matrix[i+1][j+1]==0) a++;
                    if(j+1<m && i-1>=0 && matrix[i-1][j+1]==0) a++;
                    if(j-1>=0 && i+1<n && matrix[i+1][j-1]==0) a++;
                    if(j-1>=0 && i-1>=0 && matrix[i-1][j-1]==0) a++;
                    
                    //cout<<i<<" "<<j<<" "<<a<<endl;
                    
                    if(a%2==0 && a>0) ans++;
                    
                }
            }
        }
        return ans;
    }
};
