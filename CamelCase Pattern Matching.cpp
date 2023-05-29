struct Node
{
    Node *links[26];
    vector<int>end;
    
    bool contain_key(char c)
    {
        if(links[int(c)-65]!=NULL)
        {
            return true;
        }
        return false;
    }
    void put(char c,Node *node)
    {
        links[int(c)-65]=node;
    }
    Node *get(char c)
    {
        return links[int(c)-65];
    }
};

void add(Node *node,string &s,int index)
{
    Node *root=node;
    for(int i=0;i<s.size();i++)
    {
        if(int(s[i])<97)
        {
            if(!root->contain_key(s[i]))
            {
                root->put(s[i],new Node());
            }
            
            root=root->get(s[i]);
            root->end.push_back(index);
        }
    }
    
}
vector<int> check(Node *node,string &s)
{
    Node *root=node;
    for(int i=0;i<s.size();i++)
    {
        if(!root->contain_key(s[i]))
        {
            return {};
        }
        root=root->get(s[i]);
    }
    return root->end;
}
class Solution 
{
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) 
    {
        int n=N;
        
        Node *root=new Node();
        for(int i=0;i<N;i++)
        {
            add(root,Dictionary[i],i);
        }
        auto ans=check(root,Pattern);
        if(ans.size()==0)
        {
            return {"-1"};
        }
        vector<string>a;
        for(auto x:ans)
        {
            a.push_back(Dictionary[x]);
        }
        sort(a.begin(),a.end());
        return a;
    }
};
