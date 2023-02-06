#define ll long long

Node* dfs(Node *root,int target)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==target)
    {
        return root;
    }
    if(root->data>target)
    {
        return dfs(root->left,target);
    }
    return dfs(root->right,target);
}

ll int sum(Node *root,int deviation)
{
    if(root==NULL)
    {
        return 0;
    }
    ll int ans=0;
    if(deviation==0)
    {
        ans=root->data;
    }
    return ans+sum(root->left,deviation-1)+sum(root->right,deviation+1);
}
class Solution{
public:
    long long int verticallyDownBST(Node *root,int target)
    {
        Node *node=dfs(root,target);
        if(node==NULL)
        {
            return -1;
        }
        return sum(node,0)-node->data;
    }
};
