void dfs(Node *root,Node *&suc,int key)
{
    if(root==NULL)
    {
        return;
    }
   
    
    if(root->key>key)
    {
        suc=root;
        dfs(root->left,suc,key);
    }
    else
    {
        dfs(root->right,suc,key);
    }
}
void dfs2(Node *root,Node *&pre,int key)
{
    if(root==NULL)
    {
        return;
    }
    
    if(root->key>=key)
    {
        dfs2(root->left,pre,key);
    }
    else
    {
        pre=root;
        dfs2(root->right,pre,key);
    }
}
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre=NULL;
        suc=NULL;
        dfs(root,suc,key);
        dfs2(root,pre,key);
    }
};
