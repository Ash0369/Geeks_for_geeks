class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        struct Node *ptr=head;
        struct Node *dummy=new struct Node(-1);
        struct Node *prev=dummy;
        while(ptr!=NULL && ptr->next!=NULL)
        {
            prev->next=ptr->next;
            struct Node *temp=ptr->next->next;
            prev->next->next=ptr;
            ptr->next=temp;
            prev=ptr;
            ptr=ptr->next;
        }
        if(dummy->next==NULL)
        {
            return head;
        }
        return dummy->next;
    }
};
