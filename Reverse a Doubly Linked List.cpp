class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        Node *ans=head;
        while(head!=NULL)
        {
            
            if(head->next)
            {
                Node *temp=head->next;
                head->next=head->prev;
                head->prev=temp;
                head=temp;
                
            }
            else{
                head->next=head->prev;
                head->prev=NULL;
                ans=head;
                break;
            }
            
        }
        return ans;
        
    }
};
