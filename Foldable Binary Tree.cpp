bool check(Node *root1,Node *root2)
{
    if(root1!=NULL && root2!=NULL)
    {
        bool a=check(root1->left,root2->right);
        bool b=check(root1->right,root2->left);
        return a&b;
    }
    else if(root1==NULL && root2==NULL)
    {
        return true;
    }
    return false;
}
bool IsFoldable(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    return check(root->left,root->right);
}
