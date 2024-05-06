vector<int>ans;
void dfs(Node *node)
{
    if(node==NULL)
    {
        return;
    }
    dfs(node->left);
    dfs(node->right);
    
    if(node->left==NULL && node->right==NULL)
    {
        
    }
    else if(node->left==NULL)
    {
        ans.push_back(node->right->data);
    }
    else if(node->right==NULL)
    {
        ans.push_back(node->left->data);
    }
}
vector<int> noSibling(Node* node)
{
    ans.clear();
    dfs(node);
    sort(ans.begin(),ans.end());
    if(ans.size()==0)
    {
        return {-1};
    }
    return ans;
}
