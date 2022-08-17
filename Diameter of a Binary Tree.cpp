int d=INT_MIN;
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int a=height(root->left);
    int b=height(root->right);

    d=max(d,a+b+1);
    return max(a,b)+1;
}
class Solution 
{
  public:
    
    int diameter(Node* root) 
    {
        d=INT_MIN;
        height(root);
        return d;
    }
};
