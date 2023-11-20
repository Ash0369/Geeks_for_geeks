int mod=1000000007;
#define ll long long
vector<ll int>dp(200000,0);
int dfs(Node *root,int k,map<int,int>&mp,int sum)
{
    if(root==NULL)
    {
        return 0;
    }
    int c=0;
    sum+=root->data;
    if(mp.find(sum-k)!=mp.end())
    {
        c+=mp[sum-k];
    }
    mp[sum]++;
    
    int l=dfs(root->left,k,mp,sum);
   
    int r=dfs(root->right,k,mp,sum);
    
    mp[sum]--;
    return c+l+r;
}
class Solution{
  public:
    int sumK(Node *root,int k)
    {
        map<int,int>mp;
        mp[0]++;
        return dfs(root,k,mp,0);
    }
};
