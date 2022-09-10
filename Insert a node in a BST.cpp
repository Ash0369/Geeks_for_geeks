void insertion(Node *root,int key)
{
    if(root->data==key)
    {
        return;
    }
    
    if(root->data>key)
    {
        if(root->left==NULL)
        {
            Node *temp=new Node(key);
            root->left=temp;
        }
        else
        {
            insertion(root->left,key);
        }
    }
    else if(root->data< key)
    {
        
        if(root->right==NULL)
        {
            Node *temp=new Node(key);
            root->right=temp;
        }
        else
        {
            insertion(root->right,key);
        }
    }
}
Node* insert(Node* root, int key) 
{
    insertion(root,key);
}
