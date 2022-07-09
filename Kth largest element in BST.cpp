int counter=0;
int result;
void traversal(Node* root,int k)
{
    if(root==NULL)
    {
        return;
    }

    traversal(root->right,k);
    
    counter++;
    if(counter==k)
    {
        result=root->data;
    }
    traversal(root->left,k);
}
class Solution
{
    public:
    int kthLargest(Node *root, int k)
    {
        counter=0;
        traversal(root,k);
        return result;
    }
};
