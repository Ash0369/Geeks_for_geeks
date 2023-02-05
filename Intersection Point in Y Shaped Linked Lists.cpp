class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        Node *first=head1;
        Node *second=head2;
        
        while(first!=NULL && second!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        int cnt=0;
        if(first==NULL)
        {
            while(second!=NULL)
            {
                second=second->next;
                cnt++;
            }
            first=head1;
            second=head2;
            while(cnt>0)
            {
                second=second->next;
                cnt--;
            }
        }
        else if(second==NULL)
        {
            while(first!=NULL)
            {
                first=first->next;
                cnt++;
            }
            first=head1;
            second=head2;
            while(cnt>0)
            {
                first=first->next;
                cnt--;
            }
        }
        
        while(first!=second)
        {
            first=first->next;
            second=second->next;
        }
        
        return first->data;
    }
};
