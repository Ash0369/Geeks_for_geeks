int small(Node *root,int &k)
{
    if(root==NULL)
    {
        return -1;
    }
    int a=small(root->left,k);
    if(a!=-1)
    {
        return a;
    }
    k--;
    if(k==0)
    {
        return root->data;
    }
    return small(root->right,k);
}

class Solution 
{
  public:
    
    int KthSmallestElement(Node *root, int k) 
    {
        return small(root,k);
    }
};
