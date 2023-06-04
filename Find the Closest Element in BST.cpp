int dfs(Node *root,int k)
{
    if(root==NULL)
    {
        return 1e9;
    }
    int v=root->data;
    int ans1=1e9;
    int ans2=1e9;
    if(v<k)
    {
        ans1=dfs(root->right,k);
    }
    else
    {
        ans2=dfs(root->left,k);
    }
    return min(ans1,min(ans2,abs(v-k)));
}
class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        return dfs(root,K);
    }
};
