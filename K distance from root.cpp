vector<int>ans;
void dfs(Node *root,int k)
{
    if(root==NULL){
        return;
    }
    if(k==0)
    {
        ans.push_back(root->data);
        return;
    }
    dfs(root->left,k-1);
    dfs(root->right,k-1);
}
class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        ans.clear();
        dfs(root,k);
        return ans;
    }
};
