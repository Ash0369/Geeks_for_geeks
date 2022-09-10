Node* lca(Node *root,int n1,int n2)
{
    if(root==NULL) 
    {
        return root;
    }
    if((n1>=root->data && n2<=root->data) || (n1<=root->data && n2>=root->data))
    {
        return root;
    }
    
    if(n1>root->data)
    {
        Node *temp=lca(root->right,n1,n2);
        if(temp!=NULL)
        {
            return temp;
        }
    }
    return lca(root->left,n1,n2);
}

//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
    return lca(root,n1,n2);
}
