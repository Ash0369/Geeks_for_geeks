int ans=0;
int le=0;
void dfs(Node *root,int s,int l)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        if((l+1)>le)
        {
            le=l+1;
            ans=s+root->data;
        }
        else if(l+1==le)
        {
            ans=max(ans,s+root->data);
        }
    }
    dfs(root->left,s+root->data,l+1);
    dfs(root->right,s+root->data,l+1);
}
class Solution
{
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        ans=0;
        le=0;
        dfs(root,0,0);
        return ans;
    }
};
