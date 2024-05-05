class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        vector<int>ans(20005,0);
        queue<pair<Node*,int>>q;
        
        q.push({root,10000});
        
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if(node.first==NULL){
                continue;
            }
            ans[node.second]+=node.first->data;
            
            q.push({node.first->left,node.second-1});
            q.push({node.first->right,node.second+1});
        }
        vector<int>c;
        for(auto x:ans){
            if(x>0){
                c.push_back(x);
            }
        }
        return c;
    }
};
