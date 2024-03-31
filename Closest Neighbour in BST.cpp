int ans=0;
void dfs(Node *root,int n)
{
    if(root==NULL) return;
    if(root->key<=n)
    {
        ans=max(ans,root->key);
    }
     dfs(root->right,n);
     dfs(root->left,n);
    
}
class Solution {
  public:
    int findMaxForN(Node* root, int n) {
        ans=-1;
        dfs(root,n);
        return ans;
    }
};
