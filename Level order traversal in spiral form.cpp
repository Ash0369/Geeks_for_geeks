vector<int> findSpiral(Node *root)
{
    vector<int>ans;
    
    queue<Node*>q;
    q.push(root);
    int level=0;
    while(!q.empty())
    {
        int sz=q.size();
        vector<int>temp;
        while(sz--){
        auto node=q.front();
        if(node->left)
        {
            q.push(node->left);
        }
        
        if(node->right)
        {
            q.push(node->right);
            
        }
        
        q.pop();
        
        temp.push_back(node->data);
        }
        
        if(level%2==0)
        {
            reverse(temp.begin(),temp.end());
        }
        level++;
        for(auto x:temp)
        {
            ans.push_back(x);
        }
        
    }
    
    return ans;
}
