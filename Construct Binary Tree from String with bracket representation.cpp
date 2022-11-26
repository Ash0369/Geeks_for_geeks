Node *dfs(string &s,int &index)
{
    int len=s.length();
    if(index>=len)
    {
        return NULL;
    }
    string temp="";
    while(s[index]!=')' && s[index]!='(')
    {
        temp.push_back(s[index]);
        index++;
    }
    Node *n=new Node(stoi(temp));
    if(s[index]==')')
    {
        return n;
    }
    
    if(s[index]=='(')
    {
        index+=1;
        n->left=dfs(s,index);
    }
    if(index+1<len && s[index+1]=='(')
    {
        index+=2;
        n->right=dfs(s,index);
    }
   
    index++;
    
    return n;
}
class Solution
{
public:
    // function to construct tree from string
    Node *treeFromString(string str)
    {
        Node *root;
        int a=0;
        return dfs(str,a);
    }
};
