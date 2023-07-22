class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        map<int,int>mp;
        
        Node *ptr=head;
        while(ptr!=NULL)
        {
            mp[ptr->data]=1;
            Node *curr=ptr;
            while(ptr!=NULL && mp[ptr->data]==1)
            {
                ptr=ptr->next;
            }
            curr->next=ptr;
        }
        return head;
    }
};
