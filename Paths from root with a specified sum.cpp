vector<vector<int>>ans;

void dfs(Node *root, int sum,vector<int>&curr)
{
    if(root==NULL)
    {
        return;
    }
    sum-=root->key;
    curr.push_back(root->key);
    if(sum==0)
    {
        ans.push_back(curr);
    }
    dfs(root->left,sum,curr);
    dfs(root->right,sum,curr);
    curr.pop_back();
}
class Solution
{
    public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        ans.clear();
        vector<int>curr;
        dfs(root,sum,curr);
        return ans;
    }
};
