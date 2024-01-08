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
    
    struct Node * mergeResult(Node *list1,Node *list2)
    {
        list1=reverse(list1);
        list2=reverse(list2);
        Node* p1=list1;
        Node* p2=list2;
        Node* head=new Node();
        Node *curr=head;
        while(p1!=NULL || p2!=NULL)
        {
            if(p1!=NULL && p2!=NULL)
            {
                if(p1->data<p2->data)
                {
                    Node *g=new Node;
                    g->data=p2->data;
                    curr->next=g;
                    p2=p2->next;
                }
                else
                {
                    Node *g=new Node;
                    g->data=p1->data;
                    curr->next=g;
                    p1=p1->next;
                }
                curr=curr->next;
            }
            else if(p1!=NULL)
            {
                curr->next=p1;
               break;
            }
            else if(p2!=NULL)
            {
                curr->next=p2;
                break;
            }
        }
        return head->next;
    }  
};
