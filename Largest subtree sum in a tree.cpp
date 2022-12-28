int res=0;
int dfs(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=dfs(root->left);
    int right=dfs(root->right);
    
    res=max(res,left);
    res=max(res,right);
    
    res=max(res,left+right+root->data);
    
    return left+right+root->data;
}
class Solution 
{
  public:
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root)
    {
        res=0;
        res=max(res,dfs(root));
        return res;
    }
};
