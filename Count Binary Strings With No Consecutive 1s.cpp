#define ll long long
const int mod=1e9+7;
vector<vector<ll int>> multiply(vector<vector<ll int>>&vec1,vector<vector<ll int>>&vec2)
{
    int n=vec1.size();
    vector<vector<ll int>>ans(n,vector<ll int>(n,0LL));
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=(ans[i][j]+(vec1[i][k]*vec2[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}
vector<vector<ll int>>matrix_exponent(vector<vector<ll int>>&vec,ll int k)
{
    int n=vec.size();
    vector<vector<ll int>>ans(n,vector<ll int>(n,0));
    for(int i=0;i<n;i++)
    {
        ans[i][i]=1LL;
    }
    while(k>0)
    {
        if(k%2==1)
        {
            ans=multiply(ans,vec);
        }
        vec=multiply(vec,vec);
        k=k/2;
    }
    return ans;
 
}
class Solution 
{
  public:
    int countStrings(long long int N) 
    {
        ll int n=N;
        vector<vector<ll int>>vec={{1,1},{1,0}};
        auto v=matrix_exponent(vec,n+2);
        ll int ans=v[1][0];
        return ans;
    }
};
