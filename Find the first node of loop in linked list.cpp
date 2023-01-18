//Method-1 : 

class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        map<Node*,bool>mp;
        Node *ptr=head;
        while(ptr!=NULL)
        {
            if(mp.find(ptr)!=mp.end())
            {
                return ptr->data;
            }
            mp[ptr]=true;
            ptr=ptr->next;
        }
        return -1;
    }
};


//Method-2 : 

class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        Node *slow=head;
        Node *fast=head;
        bool res=false;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                res=true;
                break;
            }
        }
        if(res==false)
        {
            return -1;
        }
        slow=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast->data;
    }
};
