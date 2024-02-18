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
    return dfs(root->left)+dfs(root->right);
}
class Solution
{
    public:
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root )
        {
             return dfs(root);
        }
};
