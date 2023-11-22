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
    return dfs(root1->right,root2->left)&dfs(root1->left,root2->right);
}
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
        if(root==NULL)
        {
            return true;
        }
	    return dfs(root->left,root->right);
    }
};
