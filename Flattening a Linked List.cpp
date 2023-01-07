class Solution 
{
public:
    Node* MergeNodes(Node* node1,Node* node2)
    {
        if(!node1) return node2 ;
        if(!node2) return node1 ;
        Node*ans ;
        if(node1->data >= node2->data)
        {
            ans = node2 ;
            ans->bottom = MergeNodes(node1,node2->bottom);
        }
        else
        {
            ans = node1 ;
            ans->bottom = MergeNodes(node1->bottom,node2);
        }
        return ans ;
    }
    Node *flatten(Node *root)
    {
        if(!root || !(root->next)) return  root;
        return MergeNodes(root,flatten(root->next));
    }
};
