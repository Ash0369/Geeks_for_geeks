class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >&matrix, int n) 
    { 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=j)
                {
                    continue;
                }
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n/2;i++)
        {
            swap(matrix[i],matrix[n-1-i]);
        }
        
    } 
};
