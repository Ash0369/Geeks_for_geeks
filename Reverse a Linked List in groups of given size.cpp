class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
       if(head==NULL)
       {
           return NULL;
       }
       node *prev=NULL;
       node *curr=head;
       node *next=NULL;
       
       int cnt=0;
       
       while(curr!=NULL && cnt<k)
       {
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
           cnt++;
       }
       
       if(next!=NULL)
       {
           head->next=reverse(next,k);
       }
       return prev;
    }
};
