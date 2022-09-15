//Method-1 : Linear Search : 

class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int key) 
    {
        for(auto x:matrix)
        {
            for(auto y:x)
            {
                if(y==key)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


//Method-2 : 

int bs(vector<vector<int> >&matrix,int n,int m,int key)
{
    if(n>=matrix.size() || m<0)
    {
        return false;
    }
    int val=matrix[n][m];
    if(val==key)
    {
        return true;
    }
    else if(val>key)
    {
        return bs(matrix,n,m-1,key);
    }
    return bs(matrix,n+1,m,key);
}
class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int key) 
    {
        return bs(matrix,0,m-1,key);
    }
};
