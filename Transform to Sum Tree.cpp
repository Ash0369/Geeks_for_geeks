int sum_tree(Node* node)
{
    if(node==NULL)
    {
        return 0;
    }
    int sum_left=sum_tree(node->left);
    int sum_right=sum_tree(node->right);
    int temp=node->data;
    node->data=sum_left+sum_right;
    return temp+sum_left+sum_right;
}

class Solution 
{
  public:
  
    void toSumTree(Node *node)
    {
        sum_tree(node);
    }
};
