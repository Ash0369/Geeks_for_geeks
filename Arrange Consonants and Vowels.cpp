bool check(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
        return true;
    }
    return false;
}
class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        
       Node *vowel=new Node('*');
       Node *cons=new Node('*');
       
       Node *ptr=head;
       
       Node *v=vowel;
       Node *c=cons;
       
       while(ptr!=NULL)
       {
           if(check(ptr->data))
           {
               v->next=ptr;
               v=v->next;
           }
           else
           {
               c->next=ptr;
               c=c->next;
           }
           ptr=ptr->next;
       }
       v->next=cons->next;
       c->next=NULL;
       return vowel->next;
    }
};
