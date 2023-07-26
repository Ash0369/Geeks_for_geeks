int ans;
int dfs(Node *root,int node,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    int l=dfs(root->left,node,k);
    int r=dfs(root->right,node,k);
    
    if(l==k || r==k)
    {
        ans=root->data;
        return k+1;
    }
    if(root->data==node)
    {
        return 1;
    }
    if(l!=-1 )
    {
        return l+1;
    }
    if(r!=-1)
    {
        return r+1;
    }
    return -1;
}

int kthAncestor(Node *root, int k, int node)
{
    ans=-1;
    dfs(root,node,k);
    return ans;
}
