bool ans=true;
int dfs(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return root->data;
    }
    int a=dfs(root->left);
    int b=dfs(root->right);
    
    if(root->data!=(a+b))
    {
        ans=false;
    }
    return a+b+root->data;
}
class Solution
{
    public:
    bool isSumTree(Node* root)
    {
        ans=true;
        dfs(root);
        return ans;
    }
};
