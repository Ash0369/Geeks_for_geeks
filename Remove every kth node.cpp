class Solution {
    public:
    Node* deleteK(Node *head,int k){
      if(k==1){
          return NULL;
      }
      Node *ptr=head;
      int a=k-1;
      
      while(ptr!=NULL){
          a--;
          if(a==0){
              if(ptr->next!=NULL){
                  ptr->next=ptr->next->next;
              }
              a=k-1;
          }
          ptr=ptr->next;
      }
      return head;
    }
};
