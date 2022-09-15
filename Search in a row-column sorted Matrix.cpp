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
