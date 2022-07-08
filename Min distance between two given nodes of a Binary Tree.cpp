//Finding LCA

Node* LCA(Node* root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a || root->data==b)
    {
        return root;
    }
    Node* left=LCA(root->left,a,b);
    Node* right=LCA(root->right,a,b);

    if(left!=NULL && right!=NULL) //We got a and b one in left and one in right subtree.
    {
        return root;
    }
    if(left==NULL && right==NULL)
    {
        return NULL;
    }
    if(left!=NULL)
    {
        //Both are in left
        return left;
    }
    
    return right;
    
}

//Finding distnce of a and b from LCA

int distance(Node* root,int x,int intial)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==x)
    {
        return intial;
    }
    int left=distance(root->left,x,intial+1);
    if(left!=-1)
    {
        return left;
    }
    int right=distance(root->right,x,intial+1);
    if(right!=-1)
    {
        return right;
    }

    return -1;
}
class Solution
{
    public:

    int findDist(Node* root, int a, int b) 
    {

       Node* lca=LCA(root,a,b);
       int d1=distance(lca,a,0);
       int d2=distance(lca,b,0);

       return d1+d2;
    }
};
