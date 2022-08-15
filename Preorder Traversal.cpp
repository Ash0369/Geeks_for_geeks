void traversal(Node* root ,vector<int>&res)
{
    if(root==NULL)
    {
        return;
    }
    res.push_back(root->data);
    traversal(root->left,res);
    traversal(root->right,res);
}
vector <int> preorder(Node* root)
{
    vector<int>res;
    traversal(root,res);
    return res;
}
