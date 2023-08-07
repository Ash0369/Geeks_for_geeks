class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool check(int row,int col,int k,int grid[N][N])
    {
        for(int i=0;i<N;i++)
        {
            if(grid[row][i]==k)
            {
                return false;
            }
            if(grid[i][col]==k)
            {
                return false;
            }
            if(grid[(row/3)*3 + (i/3)][(col/3)*3 + (i%3)]==k)
            {
                return false;
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    bool SolveSudoku(int grid[N][N],int i=0,int j=0) 
    {
        if(i==9)
        {
            return true;  
        }
        if(j==9)
        {
            return SolveSudoku(grid,i+1,0);
        }
        if(grid[i][j]==0)
        {
            for(int k=1;k<=9;k++)
            {
                if(check(i,j,k,grid)==false)
                {
                    continue;
                }
                grid[i][j]=k;
                if(SolveSudoku(grid,i,j+1))
                {
                    return true;
                }
                grid[i][j]=0;
            }
            return false;
        }
        else
        {
            return SolveSudoku(grid,i,j+1);
        }
    }
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
           // cout<<endl;
        }
    }
};
