int sum(Node *root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    int val=root->data;
    if(root->left==NULL && root->right==NULL)
    {
        return val;
    }
    return root->data+min(sum(root->right),sum(root->left));
    
}
int dfs(Node *root,int target)
{
    if(root==NULL)
    {
        return 1e9;
    }
    if(root->data==target)
    {
        if(root->left==NULL && root->right==NULL)
        {
            return 0;
        }
        if(root->left==NULL)
        {
            return -1*sum(root->right);
        }
        if(root->right==NULL)
        {
            return -1*sum(root->left);
        }
        return -1*min(sum(root->left),sum(root->right));
    }
    int left=1e9;
    int right=1e9;
    if(target<root->data)
    {
        left=dfs(root->left,target);
    }
    else if(target>root->data)
    {
        right=dfs(root->right,target);
    }
    
    if(left==1e9 && right==1e9)
    {
        return 1e9;
    }
    if(left==1e9)
    {
        return right+root->data;
    }
    return left+root->data;
}
class Solution
{
public:
    int maxDifferenceBST(Node *root,int target)
    {
        int val=dfs(root,target);
        if(val==1e9)
        {
            return -1;
        }
        return val;
    }
};
