struct Node
{
    Node *links[26];
    bool end=false;
    
    bool exist(char ch)
    {
        return links[int(ch)-97]!=NULL;
    }
    void create(char ch,Node *node)
    {
        links[int(ch)-97]=node;
    }
};
void make(string &s,Node *node)
{
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(!node->exist(c))
        {
            node->create(c,new Node());
        }
        node=node->links[int(c)-97];
    }
    node->end=true;
}
int search(Node *node,string &s)
{
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(!node->exist(c))
        {
            break;
        }
        ans++;
        node=node->links[int(c)-97];
    }
    return ans;
}
class Solution
{   
public:
    int klengthpref(string arr[], int n, int k, string str)
    {    
        Node *root=new Node();
        make(str,root);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int v=search(root,arr[i]);
            if(v>=k)
            {
                ans++;
            }
        }
        return ans;
    }
};
