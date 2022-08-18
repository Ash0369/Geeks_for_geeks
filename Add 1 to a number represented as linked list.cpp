//Method-1 : 

void search(Node *head,int &carry)
{
    if(head->next==NULL)
    {
        if(head->data==9)
        {
            head->data=0;
            carry=1;
            
        }
        else
        {
            head->data=head->data+1;
            carry=0;
        }
        return;
    }
    search(head->next,carry);
    if(carry==1)
    {
        if(head->data==9)
        {
            head->data=0;
            carry=1;
            
        }
        else
        {
            head->data=head->data+1;
            carry=0;
        }
        return;
    }
    else
    {
        return;
    }

}
class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        int carry=0;
        search(head,carry);
        if(carry==0)
        {
            return head;
        }
        else
        {
            Node *temp=new Node(1);
            temp->next=head;
            return temp;
        }
    }
};

//Method-2 : 


void search(Node *head,int &carry)
{
    if(head==NULL)
    {
        return;
    }
    search(head->next,carry);
    if(carry==1)
    {
        if(head->data==9)
        {
            head->data=0;
            carry=1;
            
        }
        else
        {
            head->data=head->data+1;
            carry=0;
        }
        return;
    }
    else
    {
        return;
    }

}
class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        int carry=1;
        search(head,carry);
        if(carry==0)
        {
            return head;
        }
        else
        {
            Node *temp=new Node(1);
            temp->next=head;
            return temp;
        }
    }
};
