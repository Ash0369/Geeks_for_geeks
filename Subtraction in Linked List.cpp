pair<Node*,int> sub(Node *head1,Node *head2)
{
    if(head1==NULL)
    {
        return {NULL,0};
    }
    auto f=sub(head1->next,head2->next);
    Node *till=f.first;
    int by=f.second;
    
    if(by>0)
    {
        head1->data=(head1->data)-1;
    }
    int g=0;
    if(head1->data<head2->data)
    {
        g++;
        head1->data=(head1->data)+10;
    }
    
    Node *t=new Node((head1->data)-(head2->data));
    t->next=till;
    return {t,g};
}
int len(Node *head)
{
    int ans=0;
    while(head!=NULL)
    {
        head=head->next;
        ans++;
    }
    return ans;
}
class Solution 
{
public:
    Node* subLinkedList(Node* head1, Node* head2) 
    {
        int len1=len(head1);
        int len2=len(head2);
        
        while(len1>len2)
        {
            Node *node=new Node(0);
            node->next=head2;
            head2=node;
            len2++;
        }
        while(len2>len1)
        {
            Node *node=new Node(0);
            node->next=head1;
            head1=node;
            len1++;
        }
        auto res=sub(head1,head2);
        if(res.second==0)
        {
            auto r=res.first;
            while(r!=NULL && r->data==0 && r->next!=NULL)
            {
                r=r->next;
            }
            return r;
        }
        auto r=sub(head2,head1).first;
        while(r!=NULL && r->data==0 && r->next!=NULL)
        {
            r=r->next;
        }
        return r;
    }
};
