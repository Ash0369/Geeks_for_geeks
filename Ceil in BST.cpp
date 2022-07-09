int findCeil(struct Node* root, int input) 
{
    int ceil=0;
    while(root!=NULL)
    {
        if(root->data==input)
        {
            return input;
        }
        else if (root->data<input)
        {
            root=root->right;
        }
        else
        {
            ceil=root->data;
            root=root->left;   
        }
    }
    return ceil;
}
