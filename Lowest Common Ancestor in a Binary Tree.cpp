Node* find_lca(Node *root,int n1,int n2)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }

    Node *l=find_lca(root->left,n1,n2);
    Node *r=find_lca(root->right,n1,n2);

    if(l==NULL && r==NULL)
    {
        return NULL;
    }

    if(l!=NULL && r!=NULL)
    {
        return root;
    }

    if(l!=NULL)
    {
        return l;
    }

    if(r!=NULL)
    {
        return r;
    }
   
}
class Solution
{
    public:
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        return find_lca(root,n1,n2);
    }
};
