void inorder(Node *root,vector<int>&vec)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
    
}
// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        vector<int>vec;
        inorder(root,vec);
        Node *dummy_head=new Node();
        Node *ptr=dummy_head;
        for(int i=0;i<vec.size();i++)
        {
            Node *temp=new Node();
            temp->data=vec[i];
            ptr->right=temp;
            temp->left=ptr;
            ptr=ptr->right;
        }
        ptr->right=NULL;
        Node *temp=dummy_head->right;
        temp->left=NULL;
        return temp;
    }
};
