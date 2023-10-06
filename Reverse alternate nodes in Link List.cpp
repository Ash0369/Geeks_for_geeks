struct Node *reverse(struct Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    auto ans=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return ans;
}
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        struct Node *ptr=odd;
        struct Node *dummy=new struct Node(-1);
        struct Node *dptr=dummy;
        while(ptr!=NULL)
        {
            dptr->next=ptr->next;
            dptr=dptr->next;
            if(ptr->next!=NULL)
            {
                ptr->next=ptr->next->next;
                ptr=ptr->next;
            }
            else
            {
                ptr=ptr->next;
            }
        }
        ptr=odd;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        auto ans=reverse(dummy->next);
        ptr->next=ans;
    }
};
