class Solution 
{
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) 
    {
        vector<Node*>ans;
        Node* left=head;
        vector<int>dp(26,0);
        vector<int>curr(26,0);
        for(auto &x:s)
        {
            dp[x-'a']++;
        }
        int n=s.size();
        int len=0;
        Node *node=head;
        while(node!=NULL)
        {
            len++;
            char c=node->data;
            curr[c-'a']++;
            
            if(len<n)
            {
                node=node->next;
                continue;
            }
            if(len==n)
            {
                if(dp==curr)
                {
                    Node *nxt=node->next;
                    node->next=NULL;
                    ans.push_back(left);
                    for(int i=0;i<26;i++)
                    {
                        curr[i]=0;
                    }
                    node=nxt;
                    left=nxt;
                    len=0;
                }
                else
                {
                    curr[(left->data)-'a']--;
                    left=left->next;
                    node=node->next;
                    len--;
                    
                }
            }
        }
        return ans;
    }
};
