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
