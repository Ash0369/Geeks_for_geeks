Node* dfs(Node *root,Node *&parent,Node *&temp)
{
    if(root==NULL)
    {
        return NULL;
    }
    dfs(root->left,parent,temp);
    if(parent==NULL)
    {
        temp=root;
        parent=root;
    }
    else{
        root->left=temp;
        temp->right=root;
        temp=root;
    }
    dfs(root->right,parent,temp);
    
}

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        Node *parent=NULL;
        Node *temp=NULL;
        
        dfs(root,parent,temp);
        
        temp->right=parent;
        parent->left=temp;
        
        return parent;
    }
};
