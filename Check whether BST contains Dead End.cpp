bool dfs1(Node *root,int l,int r)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->left==NULL && root->right==NULL)
    {
        if(l==r)
        {
            return true;
        }
        return false;
    }
    return dfs1(root->left,l,(root->data)-1)|dfs1(root->right,(root->data)+1,r);
}
class Solution
{
  public:
    bool isDeadEnd(Node *root)
    {
        return dfs1(root,1,INT_MAX);
    }
};
