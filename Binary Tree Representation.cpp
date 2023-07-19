node* dfs(int index,vector<int>&vec,node *root)
{
    if(index>=vec.size())
    {
        return NULL;
    }
    root->data=vec[index];
    
    root->left=dfs((2*index)+1,vec,new node);
    root->right=dfs((2*index)+2,vec,new node);
}
class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        dfs(0,vec,root0);
        
    }

};
