Node *removeDuplicates(Node *head)
{
    Node *prev=head;
    Node *curr=head->next;
    while(curr!=NULL)
    {
        if(curr->data==prev->data)
        {
           // cout<<curr->data<<endl;
            prev->next=curr->next;
            curr=curr->next;
            continue;
        }
        prev=curr;
        curr=curr->next;
    }
    return head;
}
