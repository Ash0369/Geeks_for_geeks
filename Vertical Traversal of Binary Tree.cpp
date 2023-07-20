void dfs(Node *root,int x,int y,map<int,map<int,vector<int>>>&mp)
{
    if(root==NULL)
    {
        return;
    }
    mp[x][y].push_back(root->data);
    dfs(root->left,x-1,y+1,mp);
    dfs(root->right,x+1,y+1,mp);
}

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int>>>mp;
        dfs(root,0,0,mp);
        vector<int>ans;
        for(auto x:mp)
        {
            for(auto y:x.second)
            {
                for(auto z:y.second)
                ans.push_back(z);
            }
        }
        return ans;
    }
};
