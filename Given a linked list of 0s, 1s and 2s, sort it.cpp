class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) 
    {
        vector<int>dp(3,0);
        Node *ptr=head;
        
        while(ptr!=NULL)
        {
            dp[ptr->data]++;
            ptr=ptr->next;
        }
        
        ptr=head;
        int x=0;
        while(ptr!=NULL)
        {
            while(dp[x]==0)
            {
                x++;
            }
            ptr->data=x;
            dp[x]--;
            ptr=ptr->next;
        }
        return head;
        
        
    }
};
