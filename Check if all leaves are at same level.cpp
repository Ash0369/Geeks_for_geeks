set<int>st;
void dfs(Node *root,int l)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        st.insert(l);
        return;
    }
    dfs(root->left,l+1);
    dfs(root->right,l+1);
}
class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        st.clear();
        dfs(root,0);
        return st.size()==1;
    }
};
