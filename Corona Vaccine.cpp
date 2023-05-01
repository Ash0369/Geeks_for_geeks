int cnt=0;
int dfs(Node *root)
{
    if(root==NULL)
    {
        return 1;
    }
    int l=dfs(root->left);
    int r=dfs(root->right);
    
    if(l==3 || r==3)
    {
        cnt++;
        return 2;
    }
    
    if(l==2 || r==2)
    {
        return 1;
    }
    return 3;
}
class Solution
{
public:
    int supplyVaccine(Node* root)
    {
        cnt=0;
        int ans=dfs(root);
        if(ans==3)
        {
            cnt++;
        }
        return cnt;
    }
};
