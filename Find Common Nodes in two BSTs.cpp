vector<int>ans;
void dfs(Node *root1,map<int,int>&mp)
{
    if(root1==NULL)
    {
        return;
    }
    mp[root1->data]++;
    dfs(root1->left,mp);
    dfs(root1->right,mp);
}
class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        ans.clear();
        map<int,int>mp;
        dfs(root1,mp);
        dfs(root2,mp);
        for(auto x:mp)
        {
            if(x.second>1)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};
