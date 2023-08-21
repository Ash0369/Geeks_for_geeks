class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int>r;
        vector<int>co;
        for(int i=0;i<n;i++)
        {
            int c=0;
            int c1=0;
            for(int j=0;j<n;j++)
            {
                c+=matrix[i][j];
                c1+=matrix[j][i];
            }
            r.push_back(c);
            co.push_back(c1);
            
        }
        
        int mx=0;
        for(auto x:r) mx=max(mx,x);
        for(auto x:co) mx=max(mx,x);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int x=r[i];
                int y=co[j];
                
                int d=min(mx-x,mx-y);
                ans+=d;
                r[i]+=d;
                co[j]+=d;
            }
        }
        return ans;
    } 
};
