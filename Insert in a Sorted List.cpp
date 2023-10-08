class Solution
{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) 
    {
        if(head->data>=data)
        {
            struct Node *ptr=new struct Node(data);
            ptr->next=head;
            return ptr;
        }
        struct Node *prev=head;
        struct Node *ptr=head;
        
        while(ptr!=NULL && ptr->data<data)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        struct Node *temp=new struct Node(data);
        prev->next=temp;
        temp->next=ptr;
        
        return head;
    }
};
