struct Node
{
    Node *links[26];
    bool flag=false;
    
    bool contain(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    void put(char c,Node *node)
    {
        links[c-'a']=node;
    }
    
    Node *get(char c)
    {
        return links[c-'a'];
    }
};

void insert(string word,Node *root)
{
    Node *node=root;
    for(int i=0;i<word.size();i++)
    {
        if(!node->contain(word[i]))
        {
            node->put(word[i],new Node());
        }
        node=node->get(word[i]);
        node->flag=true;
    }
}

bool starts_with(string &prefix,Node *root)
{
    Node *node=root;
    for(int i=0;i<prefix.size();i++)
    {
        if(!node->contain(prefix[i]))
        {
            return false;
        }
        node=node->get(prefix[i]);
    }
    return true;
}
class Solution
{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2)
    {
        Node *rootf=new Node();
        Node *rootr=new Node();
        for(auto x:s1)
        {
            insert(x,rootf);
        }
        for(int i=0;i<s1.size();i++)
        {
            string a=s1[i];
            reverse(a.begin(),a.end());
            insert(a,rootr);
        }
        
        int cnt=0;
        
        for(int i=0;i<s2.size();i++)
        {
            string s=s2[i];
            if(starts_with(s,rootf))
            {
                cnt++;
            }
            else
            {
                reverse(s.begin(),s.end());
                if(starts_with(s,rootr))
                {
                    cnt++;
                }
            }
        }
        
        return cnt;
        
        
    }
};
