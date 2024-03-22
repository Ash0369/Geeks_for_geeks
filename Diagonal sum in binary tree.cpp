class Solution
{
    public:
    vector <int> diagonalSum(Node* root)
    {
        vector<int>ans;
        
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int val=0;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto node=q.front();
                q.pop();
                
                while(node!=NULL)
                {
                    if(node->left)
                    {
                        q.push(node->left);
                    }
                    val+=node->data;
                    node=node->right;
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};
