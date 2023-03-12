class Solution 
{
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) 
    {
        int mx=0;
        int r=0;
        int n=N;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            int ind=upper_bound(mat[i].begin(),mat[i].end(),0)-mat[i].begin();
            if(ind==n)
            {
                cnt=0;
            }
            else
            {
                cnt=n-ind;
            }
            if(cnt>mx)
            {
                mx=cnt;
                r=i;
            }
        }
        return {r,mx};
    }
};
