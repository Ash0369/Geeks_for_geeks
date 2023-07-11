class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int matrix[MAX][MAX],int n,int m,int k)
    {
 		//int m=matrix.size();
        //int n=matrix[0].size();
        swap(n,m);
        vector<int>ans;
        int left=0;
        int right=n-1;
        int top=0;
        int bottom=m-1;
        while(left<=right && top<=bottom)
        {
            for(int j=left;j<=right;j++)
            {
                ans.push_back(matrix[top][j]);
            }
            top++;
            for(int j=top;j<=bottom;j++)
            {
                ans.push_back(matrix[j][right]);
            }
            right--;
            for(int j=right;j>=left;j--)
            {
                if(top>bottom)
                {
                    continue;
                }
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
            for(int j=bottom;j>=top;j--)
            {
                if(left>right)
                {
                    continue;
                }
                ans.push_back(matrix[j][left]);
            }
            left++;
        }
        return ans[k-1];
    }
};
