//Method-1 O(n) Time complexity and O(n) Space Complexity

vector<Node*>inorder;
void sucessor(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    sucessor(root->left);
    inorder.push_back(root);
    sucessor(root->right);
}
class Solution
{
  public:
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        inorder.clear();
        sucessor(root);
        int i=0;
        for(i=0;i<inorder.size();i++)
        {
            if(inorder[i]->data==x->data)
            {
                break;
            }
        }
        if(i==(inorder.size()-1))
        {

            return NULL;
        }
        return inorder[i+1];
    }
};

//Method-2 
