int findCeil(struct Node* root, int input) 
{
    
    int ele=INT_MAX;
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
            
            if((root->data-input)<ele)
            {
                ele=root->data-input;
            }
            root=root->left;
            
        }
    }
    return ele+input;
    
}
