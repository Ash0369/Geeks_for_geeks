void dfs2(Node *node,stack<Node*>&st)
{
    if(node==NULL)
    {
        return;
    }
    st.push(node);
    dfs2(node->left,st);
}
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int>ans;
       stack<Node *>st1;
       stack<Node *>st2;
       dfs2(root1,st1);
       dfs2(root2,st2);
       
       while(!st1.empty() && !st2.empty())
       {
           auto node1=st1.top();
           auto node2=st2.top();
           
           if(node1->data>=node2->data)
           {
               ans.push_back(node2->data);
               st2.pop();
               dfs2(node2->right,st2);
           }
           else
           {
               ans.push_back(node1->data);
               st1.pop();
               dfs2(node1->right,st1);
           }
       }
       
       while(!st1.empty())
       {
           auto node1=st1.top();
           ans.push_back(node1->data);
           st1.pop();
           dfs2(node1->right,st1);
       }
       while(!st2.empty())
       {
           auto node2=st2.top();
           ans.push_back(node2->data);
           st2.pop();
           dfs2(node2->right,st2);
       }
       return ans;
    }
};
