void dfs(Node *root,vector<int>&v)
{
    if(root==NULL)return;
    v.push_back(root->data);
    dfs(root->left,v);
    dfs(root->right,v);
}
void dfs2(Node *root,vector<int>&v,int &index)
{
    if(root==NULL)return;
    dfs2(root->left,v,index);
    root->data=v[index];
    index++;
    dfs2(root->right,v,index);
}
class Solution
{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>v;
        dfs(root,v);
        sort(v.begin(),v.end());
        int i=0;
        dfs2(root,v,i);
        return root;
    }
};
