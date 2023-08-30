Node* deleteNode(Node *head,int x)
{
    if(x==1)
    {
        return head->next;
    }
    Node *prev=head;
    Node *curr=head;
    while(true)
    {
        if(x==1)
        {
            prev->next=curr->next;
            break;
        }
        prev=curr;
        curr=curr->next;
        x--;
    }
    return head;
}
