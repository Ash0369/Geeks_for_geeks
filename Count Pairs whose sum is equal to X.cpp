class Solution
{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) 
    {
        unordered_map<int,int>mp;
        
        while(head1!=NULL)
        {
            mp[head1->data]++;
            head1=head1->next;
        }
        int ans=0;
        
        while(head2!=NULL)
        {
            int v=head2->data;
            v=x-v;
            ans+=mp[v];
            head2=head2->next;
        }
        return ans;
    }
};
