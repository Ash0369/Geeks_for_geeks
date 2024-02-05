class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        if(head==NULL)
        {
            Node *node=new Node(data);
            node->next=node;
            return node;
        }
        Node *prev=NULL;
        Node *curr=head;
        while(true)
        {
            if(curr->data<=data)
            {
                prev=curr;
                if(curr->next==head)
                {
                    Node *node=new Node(data);
                    curr->next=node;
                    node->next=head;
                    return head;
                }
                curr=curr->next;
            }
            else{
                Node *node=new Node(data);
                if(prev==NULL)
                {
                    node->next=head;
                    while(curr->next!=head)
                    {
                        curr=curr->next;
                    }
                    curr->next=node;
                    return node;
                }
                else{
                    prev->next=node;
                    node->next=curr;
                    return head;
                }
            }
        }
    }
};
