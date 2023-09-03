bool dfs(Node *root1,Node *root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1==NULL || root2==NULL)
    {
        return false;
    }
    if(root1->data!=root2->data)
    {
        return false;
    }
    return (dfs(root1->left,root2->left)|dfs(root1->right,root2->left))&(dfs(root1->right,root2->right)|dfs(root1->left,root2->right));
}
class Solution
{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        return dfs(root1,root2);
    }
};
