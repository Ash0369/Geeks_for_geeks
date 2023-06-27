class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        set<int>st;
        struct Node*ptr=head1;
        while(ptr!=NULL)
        {
            st.insert(ptr->data);
            ptr=ptr->next;
        }
        ptr=head2;
        while(ptr!=NULL)
        {
            st.insert(ptr->data);
            ptr=ptr->next;
        }
        struct Node *head=new Node(-1);
        ptr=head;
        for(auto x:st)
        {
            ptr->next=new Node(x);
            ptr=ptr->next;
        }
        return head->next;
    }
};
