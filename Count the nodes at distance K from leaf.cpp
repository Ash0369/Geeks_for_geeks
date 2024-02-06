set<Node*>st;
void dfs(Node *root,int h,int k,vector<Node*>&vec)
{
    if(root==NULL)
    {
        return ;
    }
    vec.push_back(root);
    if(root->left==NULL && root->right==NULL)
    {
        int g=h-k;
        if(g>=0)
        {
            st.insert(vec[g]);
        }
    }
    dfs(root->left,h+1,k,vec);
    dfs(root->right,h+1,k,vec);
    vec.pop_back();

}
class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
        st.clear();
        vector<Node*>vec;
        dfs(root,0,k,vec);
        return st.size();
    }
};
