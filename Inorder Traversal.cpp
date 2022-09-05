//Morris Traversal

class Solution 
{
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) 
    {
        // Your code here
        vector<int>inorder;
        Node *cur=root;
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                inorder.push_back(cur->data);
                cur=cur->right;
            }
            else
            {
                Node *prev=cur->left;
                while(prev->right && prev->right!=cur)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=cur; //Thread
                    cur=cur->left;
                }
                else
                {
                    prev->right=NULL;
                    inorder.push_back(cur->data);
                    cur=cur->right;
                }
            }
            
        }
        return inorder;
    }
};
