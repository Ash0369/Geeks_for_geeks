bool check(Node *root,int l,int r)
{
    if(root==NULL)
    {
        return true;
    }
    bool a=check(root->left,l,root->data);
    bool b=check(root->right,root->data,r);
    
    int l_data=INT_MIN;
    int r_data=INT_MAX;
    
    if(root->left)
    {
        l_data=root->left->data;
    }
    if(root->right)
    {
        r_data=root->right->data;
    }
    
    if(root->data>l_data && root->data<r_data && a && b && root->data>=l && root->data<=r)
    {
        return true;
    }
    return false;
}
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        return check(root,INT_MIN,INT_MAX);
    }
};
