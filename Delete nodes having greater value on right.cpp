Node *reverse(Node *head)
{
    if(head->next==NULL)
    {
        return head;
    }
    Node *nxt=head->next;
    Node *ptr=reverse(head->next);
    nxt->next=head;
    head->next=NULL;
    return ptr;
    
}
class Solution
{
    public:
    Node *compute(Node *head)
    {
        Node *hd=reverse(head);
        Node *ptr=hd;
        int v=-1;
        Node *prev=hd;
        while(ptr!=NULL)
        {
            if(ptr->data<v)
            {
                prev->next=ptr->next;
            }
            else
            {
                prev=ptr;
            }
            v=max(v,ptr->data);
            ptr=ptr->next;
        }
        return reverse(hd);
    }
    
};
