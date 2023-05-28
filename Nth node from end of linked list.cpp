int getNthFromLast(struct Node *head, int n)
{
    struct Node *fast=head;
    n--;
    while(n--)
    {
        if(fast->next==NULL)
        {
            return -1;
        }
        fast=fast->next;
    }
    struct Node *slow=head;
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow->data;
}
