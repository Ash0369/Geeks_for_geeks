int cnt=0;
int dfs(Node *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        cnt++;
        return root->data;
    }
    
    int a=root->data;
    int b=root->data;
    if(root->left)
    {
        a=dfs(root->left);
    }
    if(root->right)
    {
        b=dfs(root->right);
    }
    
    if(a==b && (a==root->data && b==root->data))
    {
        cnt++;
        return root->data;
    }
    return -1;
    
}
class Solution
{
    public:
    int singlevalued(Node *root)
    {
        cnt=0;
        dfs(root);
        return cnt;
    }
    
};
