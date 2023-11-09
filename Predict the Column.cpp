class Solution
{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>arr,int N)
    {
        int ans=0;
        int c=-1;
        int n=N;
        for(int i=0;i<n;i++)
        {
            int t=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j][i]==0)
                {
                    t++;
                }
            }
            if(t>ans)
            {
                ans=t;
                c=i;
            }
        }
        return c;
        
    }
};
