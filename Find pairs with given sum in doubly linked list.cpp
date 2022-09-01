class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>>res;
        Node *temp1=head;
        Node *temp2=head;
        while(temp2->data<target && temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        if(temp2->data>target)
        {
            temp2=temp2->prev;
        }
        while(temp2!=NULL && temp1!=NULL && (temp1->data<temp2->data))
        {
            int a=temp1->data;
            int b=temp2->data;
            
            if(a+b==target)
            {
                res.push_back(make_pair(a,b));
                temp1=temp1->next;
                temp2=temp2->prev;
            }
            else if(a+b>target)
            {
                temp2=temp2->prev;
            }
            else if(a+b<target)
            {
               temp1=temp1->next;
            }
            
        }
       
        return res;
    }
};
