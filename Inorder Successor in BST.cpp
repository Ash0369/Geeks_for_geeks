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

//Method-2 in O(h) time complexity and O(1) space complexity

Node* sucessor(Node* root,Node* x)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(x->data==root->data)
    {
        if(root->right!=NULL)
        {
            Node* temp=root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            return temp;
        }
        return NULL;
    }
    else if(x->data>root->data)
    {
        Node* temp=sucessor(root->right,x);
        if(temp==NULL)
        {
            return NULL;
        }
        return temp;
    }
    else if(x->data<root->data)
    {
        Node* temp=sucessor(root->left,x);
        if(temp==NULL)
        {
            return root;
        }
        return temp;
    }
    return root;

}
class Solution
{
  public:
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        return sucessor(root,x);
    }
};
