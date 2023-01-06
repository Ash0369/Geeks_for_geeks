map<Node*,Node*>mp;
Node *dfs(Node* tree)
{
    if(tree==NULL)
    {
        return NULL;
    }
    if(mp.find(tree)!=mp.end())
    {
        return mp[tree];
    }
    Node *temp=new Node(tree->data);
    mp[tree]=temp;
    temp->left=dfs(tree->left);
    temp->right=dfs(tree->right);
    temp->random=dfs(tree->random);
    
    return temp;
}
class Solution
{
  public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
    Node* cloneTree(Node* tree)
    {
        mp.clear();
        return dfs(tree);
    }
};
