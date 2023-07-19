void dfs(Node *root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    ans.push_back(root->data);
    if(root->left!=NULL)
    {
        dfs(root->left,ans);
    }
    else if(root->right!=NULL)
    {
        dfs(root->right,ans);
    }
}
void dfs2(Node *root,vector<int>&ans)
{
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left!=NULL)
    {
        dfs2(root->left,ans);
    }
    if(root->right!=NULL)
    {
        dfs2(root->right,ans);
    }
    
}
void dfs3(Node *root,vector<int>&ans)
{

    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return;
    }
    if(root->data==-1)
    {
        return;
    }
    ans.push_back(root->data);
    if(root->right!=NULL)
    {
        dfs3(root->right,ans);
    }
    else if(root->left!=NULL)
    {
        dfs3(root->left,ans);
    }
    
}

class Solution {
public:
    vector <int> boundary(Node *root)
    {
        if(root->left==NULL &&  root->right==NULL)
        {
            return {root->data};
        }
        vector<int>ans;
        ans.push_back(root->data);
        dfs(root->left,ans);
        dfs2(root,ans);
        vector<int>temp;
       
        dfs3(root->right,temp);
        reverse(temp.begin(),temp.end());
        for(auto x:temp)
        {
            ans.push_back(x);
        }
        
        
        return ans;
    }
};
