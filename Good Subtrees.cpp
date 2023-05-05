int ans=0;
vector<int> dfs(Node *root,int k)
{
    if(root==NULL)
    {
        vector<int>v(30,0);
        return v;
    }
    auto x=dfs(root->left,k);
    auto y=dfs(root->right,k);
    int cnt=0;
    vector<int>vec(30,0);
    for(int i=1;i<=25;i++)
    {
        if(x[i]==1 || y[i]==1)
        {
            vec[i]=1;
            cnt++;
        }
    }
    int v=root->data;
    if(vec[v]==0)
    {
        vec[v]=1;
        cnt++;
    }
    if(cnt<=k)
    {
        ans++;
    }
    return vec;
}
class Solution
{
public:
    int goodSubtrees(Node *root,int k)
    {
        ans=0;
        dfs(root,k);
        return ans;
    }
};
