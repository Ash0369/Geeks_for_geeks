class Solution 
{
  public:
    void stack_push(struct Node *root,stack<struct Node*>&st)
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
    }
    void correctBST( struct Node* root )
    {
       struct Node *prev_ptr=NULL;
       struct Node *adj_prev_ptr=NULL;
       struct Node *curr_ptr=NULL;
       struct Node *next_ptr=NULL;
        
        stack<struct Node*>st;
        
        stack_push(root,st);
        
        while(!st.empty())
        {
            curr_ptr=next_ptr;
            next_ptr=st.top();
            st.pop();
            
            if(curr_ptr && next_ptr->data<curr_ptr->data)
            {
                if(prev_ptr==NULL)
                {
                    prev_ptr=curr_ptr;
                    adj_prev_ptr=next_ptr;
                }
                else
                {
                    swap(prev_ptr->data,next_ptr->data);
                    return;
                }
            }
            stack_push(next_ptr->right,st);
        }
        
        swap(prev_ptr->data,adj_prev_ptr->data);
        return;        
    }
};
