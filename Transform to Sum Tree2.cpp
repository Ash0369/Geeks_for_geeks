int dfs(Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    if(node->left==NULL && node->right==NULL)
    {
        int d=node->data;
        node->data=0;
        return d;
    }
    int d=node->data;
    int l=dfs(node->left);
    int r=dfs(node->right);
    
    node->data=l+r;
    return l+r+d;
}
class Solution 
{
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        dfs(node);
    }
};
