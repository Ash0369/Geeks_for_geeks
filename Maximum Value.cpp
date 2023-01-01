vector<int>ans;
int height(Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    return 1+max(height(node->left),height(node->right));
}
void dfs(Node *node,int ht)
{
    if(node==NULL)
    {
        return;
    }
    ans[ht]=max(ans[ht],node->data);
    dfs(node->left,ht+1);
    dfs(node->right,ht+1);
}
class Solution 
{
  public:
    vector<int> maximumValue(Node* node) 
    {
        int h=height(node);
        ans.clear();
        ans.resize(h,0);
        dfs(node,0);
        return ans;
    }
};
