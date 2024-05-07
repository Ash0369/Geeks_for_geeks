vector<vector<int>>ans;

void dfs(Node *root,vector<int>&vec)
{
    if(root==NULL)
    {
        return;
    }
   
    vec.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(vec);
        vec.pop_back();
        return;
    }
    dfs(root->left,vec);
    dfs(root->right,vec);
    vec.pop_back();
}
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        ans.clear();
        vector<int>vec;
        dfs(root,vec);
        return ans;
    }
};
