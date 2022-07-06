vector<int>result;
bool find_ancestors(struct Node* root,int target)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==target)
    {
        return true;
    }
    bool a=find_ancestors(root->right,target);
    bool b=find_ancestors(root->left,target);
    if(a==true || b==true)
    {
        result.push_back(root->data);
        return true;
    }
    return false;
}
class Solution{
  public:
    vector<int> Ancestors(struct Node *root, int target)
    {
        result.clear();
        find_ancestors(root,target);
        return result;
    }
};
