int ans=-1;
void dfs(Node *root,int x)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data<=x)
    {
        ans=max(ans,root->data);
    }
    if(x>(root->data))
    {
        dfs(root->right,x);
    }
    else{
        dfs(root->left,x);
    }
}

class Solution{

public:
    int floor(Node* root, int x) {
        ans=-1;
        dfs(root,x);
        return ans;
    }
};
