struct Node
{
    Node *links[26];
    bool containKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
};

int countDistinctSubstring(string s)
{
    Node *root=new Node();
    int ans=0;
    for(int j=0;j<s.size();j++)
    {
        Node *node=root;
        for(int i=j;i<s.size();i++)
        {
            if(!node->containKey(s[i]))
            {
                ans++;
                node->put(s[i],new Node());
            }
            node=node->get(s[i]);
        }
    }
    return ans+1;
}
