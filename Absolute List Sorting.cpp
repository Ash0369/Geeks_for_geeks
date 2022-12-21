Node* reverse(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *g=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return g;
}
class Solution
{
    
public:
    Node* sortList(Node* head)
    {
        
        
        Node *poshead=new Node;
        Node *neghead=new Node;
        
        Node *neg=neghead;
        Node *pos=poshead;
        
        while(head!=NULL)
        {
            if((head->data)>=0)
            {
                pos->next=head;
                head=head->next;
                pos=pos->next;
                pos->next=NULL;
            }
            else
            {
                neg->next=head;
                head=head->next;
                neg=neg->next;
                neg->next=NULL;
            }
        }
        
        neghead=reverse(neghead->next);
        neg=neghead;
        while(neg!=NULL && neg->next!=NULL)
        {
            neg=neg->next;
        }
        if(neg==NULL)
        {
            return poshead->next;
        }
        neg->next=poshead->next;
        return neghead;
    }
};
