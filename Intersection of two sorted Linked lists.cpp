class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {

        Node* head=new Node(0);
        Node *head_ptr=head;
        Node* ptr1=head1;
        Node *ptr2=head2;
        
        while(ptr1!=NULL && ptr2!=NULL)
        {
            if(ptr1->data<ptr2->data)
            {
                ptr1=ptr1->next;
            }
            else if(ptr1->data>ptr2->data)
            {
                ptr2=ptr2->next;
            }
            else{
                head_ptr->next=ptr2;
                head_ptr=head_ptr->next;
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
        }
        head_ptr->next=NULL;
        return head->next;
    }
};
