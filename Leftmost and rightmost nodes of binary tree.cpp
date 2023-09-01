void printCorner(Node *root)
{
    queue<vector<Node*>>q;
    q.push({root});
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        
        vector<Node*>stage;
        for(auto x:node)
        {
            if(x->left)
            {
                stage.push_back(x->left);
            }
            if(x->right)
            {
                stage.push_back(x->right);
            }
        }
        
        cout<<node[0]->data<<" ";
        if(node.size()>1)
        {
            cout<<node[node.size()-1]->data<<" ";
        }
        
        if(stage.size()>0)
        {
            q.push(stage);
        }
        
    }
}
