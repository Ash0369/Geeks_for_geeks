map<Node*,Node*>dp;
void dfs(Node *head,Node *node)
{
    
    dp[node]=head;
    for(auto x:node->neighbors)
    {
        if(dp.find(x)==dp.end())
        {
            Node *z=new Node(x->val);
            dfs(z,x);
        }
    }
    vector<Node*>neigh;
    for(auto x:node->neighbors)
    {
        neigh.push_back(dp[x]);
    }
    head->neighbors=neigh;
    
}
class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        Node *head=new Node(node->val);
        dp.clear();
        dfs(head,node);
        return head;
    }
};
