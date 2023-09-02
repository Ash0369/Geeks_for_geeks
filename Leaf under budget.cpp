void dfs(Node *root,int level,vector<int>&c)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        c.push_back(level);
    }
    dfs(root->left,level+1,c);
    dfs(root->right,level+1,c);
}
class Solution
{
public:
    int getCount(Node *root, int k)
    {
        vector<int>c;
        dfs(root,1,c);
        sort(c.begin(),c.end());
        
        int ans=0;
        for(int i=0;i<c.size();i++)
        {
            if(c[i]<=k)
            {
                ans++;
                k=k-c[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};
