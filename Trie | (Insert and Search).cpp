void insert(struct TrieNode *root, string key)
{
    for(int i=0;i<key.size();i++)
    {
        char c=key[i];
        if(root->children[c-'a']==NULL)
        {
            struct TrieNode *node=new TrieNode();
            root->children[c-'a']=node;
            node->isLeaf=false;
        }
        root=root->children[c-'a'];
    }
    root->isLeaf=true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    for(int i=0;i<key.size();i++)
    {
        char c=key[i];
        if(root->children[c-'a']==NULL)
        {
           return false;
        }
        root=root->children[c-'a'];
    }
    return root->isLeaf;
}
