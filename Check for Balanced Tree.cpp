int check(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int a=check(root->left);
    int b=check(root->right);
    
    if(a==-1 || b==-1)
    {
        return -1;
    }
    if(abs(a-b)>1)
    {
        return -1;
    }
    return 1+max(a,b);
}
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return check(root)!=-1;
    }
};
