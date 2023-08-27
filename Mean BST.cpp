int dfs(Node *root,int key)//minimum
{
    if(root==NULL)
    {
        return -1e9;
    }
    if(root->data>key)
    {
        //look in left
        return dfs(root->left,key);
    }
    else if(root->data<=key)
    {
        int ans=root->data;
        //look in left
        return max(ans,dfs(root->right,key));
    }
}

int dfs2(Node *root,int key)//maximum
{
    if(root==NULL)
    {
        return 1e9;
    }
    if(root->data<key)
    {
        //look in left
        return dfs2(root->right,key);
    }
    else if(root->data>=key)
    {
        int ans=root->data;
        //look in left
        return min(ans,dfs2(root->left,key));
    }
}

class Solution
{
    public:
    
    int mean(Node* root, int key)
    {
        int l=dfs(root,key);
        int r=dfs2(root,key);
        //cout<<l<<" "<<r<<endl;
        
        if(l==-1e9)
        {
            l=-1;
        }
        if(r==1e9)
        {
            r=-1;
        }
        return (r+l+1)/2;
    }
};
