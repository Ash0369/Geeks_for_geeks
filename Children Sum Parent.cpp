bool check(Node *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }
    bool a=true;
    bool b=true;
    int sum=0;
    if(root->left)
    {
        sum=sum+root->left->data;
        a=check(root->left);
    }
    if(root->right)
    {
        sum=sum+root->right->data;
        b=check(root->right);
    }
    if(sum==root->data && a==true && b==true)
    {
        return true;
    }
    return false;
    
    
    
}
class Solution
{
    public:
    int isSumProperty(Node *root)
    {
        if(root==NULL)
        {
            return 1;
        }
        return check(root);
    }
    
};
