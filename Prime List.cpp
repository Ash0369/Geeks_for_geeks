bool check(int n)
{
    if(n==1 || n==0)
    {
        return false;
    }
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int prime(int val)
{
    if(check(val))
    {
        return val;
    }
    int i=1;
    while(true)
    {
        if(check(val-i))
        {
            return val-i;
        }
        if(check(val+i))
        {
            return val+i;
        }
        i++;
    }
}
class Solution
{
public:
    Node *primeList(Node *head)
    {
        Node *it=head;
        while(it!=NULL)
        {
            it->val=prime(it->val);
            it=it->next;
        }
        return head;
    }
};
