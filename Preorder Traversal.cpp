//Method-1 : Normal way

void traversal(Node* root ,vector<int>&res)
{
    if(root==NULL)
    {
        return;
    }
    res.push_back(root->data);
    traversal(root->left,res);
    traversal(root->right,res);
}
vector <int> preorder(Node* root)
{
    vector<int>res;
    traversal(root,res);
    return res;
}


//Method-2 : Morris Traversal 

vector <int> preorder(Node* root)
{
    vector<int>preorder;
    Node *cur=root;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            preorder.push_back(cur->data);
            cur=cur->right;
        }
        else
        {
            Node *prev=cur->left;
            while(prev->right && prev->right!=cur)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                preorder.push_back(cur->data);
                prev->right=cur; //Thread
                cur=cur->left;
            }
            else
            {
                prev->right=NULL;
                cur=cur->right;
            }
        }
        
    }
    return preorder;
}
