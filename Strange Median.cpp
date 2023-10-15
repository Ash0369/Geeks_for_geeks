Node *ans;
void dfs(Node *node,int &k)
{
    if(node==NULL)
    {
        return;
    }
    dfs(node->left,k);
    k=k-1;
    if(k==0)
    {
        ans=node;
    }
    dfs(node->right,k);
    
}
vector<int>p;
void dfs(Node *node)
{
    if(node==NULL)
    {
        return;
    }
    p.push_back(node->data);
    dfs(node->left);
    dfs(node->right);
}
class Solution{
    public:
    int median(Node *node,int k){
        p.clear();
        dfs(node,k);
        dfs(ans);
        
        sort(p.begin(),p.end());
       
        int sz=p.size();
        if(sz%2==0)
        {
            return (p[(sz/2)-1]+p[sz/2])/2;
        }
        return p[sz/2];
    }
};
