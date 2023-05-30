int dfs(struct Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    return 1+max(dfs(node->left),dfs(node->right));
}
class Solution
{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node)
    {
        return dfs(node);
    }
};
