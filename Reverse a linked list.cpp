Node* reverse(Node* &head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next!=NULL)
    {
        Node* temp;
        temp=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    
    return head;
    
}
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        return reverse(head);
    }
    
};
