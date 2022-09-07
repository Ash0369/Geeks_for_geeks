int search(Node *root,int &k)
{ 
    if(root==NULL)
    {
        return 0;
        
    }
    int a=0;
    if(root->left && k>0)
    {
        a=search(root->left,k);
    }
    else if(!root->left && k>0)
    {
        k=k-1;
        return root->data+search(root->right,k);
    }
    
    if(k>0)
    {
        k=k-1;
        return a+root->data+search(root->right,k);
    }
    
    return a;
}
int sum(Node* root, int k) 
{ 
     return search(root,k);
} 
