#define ll long long
ll int ans;
ll int inf=-1*1e18;
ll int pinf=1e18;
ll int tar;
vector<ll int>dfs(Node *root)
{
    if(root==NULL)
    {
        return {0,pinf,inf,0};
    }
    auto u=dfs(root->left);
    auto v=dfs(root->right);
    if(u[0]==tar)
    {
        ans=min(ans,u[3]);
    }
    if(v[0]==tar)
    {
        ans=min(ans,v[3]);
    }
    if(root->data>u[2] && root->data<v[1])
    {
        return {u[0]+v[0]+root->data,min(u[1],1LL*root->data),max(v[2],1LL*root->data),u[3]+v[3]+1};
    }
    return {-1,inf,pinf,0};
   
}
class Solution 
{
public:
    int minSubtreeSumBST(int target, Node *root) 
    {
        tar=target;
        ans=1e18;
        auto node=dfs(root);
        if(node[0]==target)
        {
            ans=min(ans,node[3]);
        }
        if(ans==1e18)
        {
            return -1;
        }
        return ans;
    }
};
