class Solution
{
    public:
    void connect(Node *root)
    {
        vector<vector<Node*>>vec;
        queue<Node*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            vec.push_back({});
            for(int i=0;i<sz;i++)
            {
                Node *node=q.front();
                q.pop();
                vec[level].push_back(node);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            level++;
        }
        for(auto x:vec)
        {
            for(int i=1;i<x.size();i++)
            {
                x[i-1]->nextRight=x[i];
            }
        }
    }    
};
