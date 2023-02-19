vector<int>inf;
void detect(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    inf.push_back(root->data);
    detect(root->left);
    detect(root->right);
}
int i=0;
void dfs(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    dfs(root->left);
    root->data=inf[i];//As 0 indexed
    i++;
    dfs(root->right);
}
class Solution 
{
  public:
    struct Node *correctBST(struct Node *root) 
    {
        inf.clear();
        detect(root);
        sort(inf.begin(),inf.end());
        i=0;
        dfs(root);
        return root;
    }
};
