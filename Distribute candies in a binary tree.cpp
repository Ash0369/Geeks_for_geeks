int ans=0;
int dfs(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int a=dfs(root->left);
    int b=dfs(root->right);
    
    ans+=abs(a)+abs(b);
    
    return a+b+root->key-1;
    
}
class Solution
{
    public:
    int distributeCandy(Node* root)
    {
        ans=0;
        dfs(root);
        return ans;
    }
};
