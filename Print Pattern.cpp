void dfs2(int n,int original,vector<int>&vec)
{
    vec.push_back(n);
    if(n!=original)
    {
        dfs2(n+5,original,vec);
    }
}
void dfs(int n,int original,vector<int>&vec)
{
    vec.push_back(n);
    if(n>0)
    {
       
        dfs(n-5,original,vec);
        
    }
    else{
        dfs2(n+5,original,vec);
    }
}

class Solution
{
public:
    vector<int> pattern(int N)
    {
        if(N<=0)
        {
            return {N};
        }
        vector<int>ans;
        dfs(N,N,ans);
        return ans;
    }
};
