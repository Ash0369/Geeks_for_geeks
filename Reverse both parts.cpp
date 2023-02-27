Node *rev(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *ans=rev(head->next);
    head->next->next=head;
    head->next=NULL;
    return ans;
    
}
class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        int cnt=0;
        Node *temp=head;
        k--;
        while(cnt<k)
        {
            temp=temp->next;
            cnt++;
        }
        Node *temp2=temp->next;
        temp->next=NULL;
        Node *a=rev(head);
        Node *b=rev(temp2);
        
        temp=a;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=b;
        
        return a;
    }
};
