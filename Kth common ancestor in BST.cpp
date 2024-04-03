int ans;
int dfs(Node *root,int k,int x,int y)
{
    if(root==NULL)
    {
        return -2;
    }
    if(root->data==x || root->data==y)
    {
        if(dfs(root->left,k,x,y)==-1 || dfs(root->right,k,x,y)==-1)
        {
            //cout<<"hi"<<endl;
            if(k==1)
            {
                ans=root->data;
                return 1e9;
            }
            else{
                return k-1;
            }
        }
        return -1;
    }
    int a1=dfs(root->left,k,x,y);
    int a2=dfs(root->right,k,x,y);
    
    if(a1>=1 || a2>=1)
    {
        if(a1==1 || a2==1)
        {
            ans=root->data;
            return 1e9;
        }
        return max(a1,a2)-1;
    }
    else{
        if(a1==-1 && a2==-1)
        {
            if(k==1)
            {
                ans=root->data;
                return 1e9;
            }
            return k-1;
        }
        if(a1==-1 || a2==-1)
        {
            return -1;
        }
        return -2;
    }
}
class Solution
{
    public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
       ans=-1;
       dfs(root,k,x,y);
       return ans;
    }
};
