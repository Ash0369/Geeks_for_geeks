class Solution
{
  public:
  void deleteKey(trie_node_t *root, char key[])
  {
      int n=sizeof(key)/sizeof(key[0]);
      n=strlen(key);
      for(int i=0;i<n;i++)
      {
          char c=key[i];
          root->value=0;
          root=root->children[c-'a'];
      }
      root->value=0;
  }
};
