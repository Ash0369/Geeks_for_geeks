//Method-1 : O(n) Space Approach


class Solution
{ 
public:
    void reorderList(Node* head) 
    {
        stack<Node*>st;
        Node *slow=head;
        Node *fast=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *bar=slow;
        slow=slow->next;
        
        while(slow!=NULL)
        {
            st.push(slow);
            slow=slow->next;
        }
        Node *ptr=head;
        while(!st.empty())
        {
            Node *temp=ptr->next;
            ptr->next=st.top();
            st.top()->next=temp;
            st.pop();
            ptr=temp;
        }
        while(ptr!=bar)
        {
            ptr=ptr->next;
        }
        ptr->next=NULL;
        
        
        
    }
};

//Method-2 : O(1) 


ListNode* reverse(ListNode* head)
{
    ListNode*curr=head;
    ListNode*prev=NULL;
    ListNode*nxt;

    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;

    }
    return prev;
}
class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* start=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* new_head=reverse(slow->next);
        slow->next=NULL;

        ListNode* temp=head;
        ListNode* temp2=new_head;

        while(temp2!=NULL)
        {
            ListNode* store=temp->next;
            temp->next=temp2;
            ListNode* store2=temp2->next;
            temp2->next=store;
            temp2=store2;
            temp=store;

        }
    }
};
