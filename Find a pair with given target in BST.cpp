void push_left_stack(struct Node*root,stack<struct Node*>&st)
{
    while(root!=NULL)
    {
        st.push(root);
        root=root->left;
    }
}
void push_right_stack(struct Node *root,stack<struct Node*>&st)
{
    while(root!=NULL)
    {
        st.push(root);
        root=root->right;
    }
}
class Solution
{
  public:
    
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        stack<struct Node*>left;
        stack<struct Node*>right;
        
        push_left_stack(root,left);
       // left.pop();
        push_right_stack(root,right);
        
        while(!left.empty() && !right.empty())
        {
            int d=left.top()->data + right.top()->data;
            if(d==target)
            {
                return true;
            }
            else if(d>target)
            {
                struct Node*temp=right.top();
                right.pop();
                push_right_stack(temp->left,right);
            }
            else if(d<target)
            {
                struct Node*temp=left.top();
                left.pop();
                push_left_stack(temp->right,left);
            }
            
        }
        return false;
    }
};
