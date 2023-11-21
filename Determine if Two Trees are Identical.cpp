
bool dfs(Node *r1, Node *r2)
{
    if(r1==NULL && r2==NULL)
    {
        return true;
    }
    if(r1==NULL || r2==NULL)
    {
        return false;
    }
    if(r1->data!=r2->data)
    {
        return false;
    }
    return dfs(r1->left,r2->left)&dfs(r1->right,r2->right);
    
}
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        return dfs(r1,r2);
    }
};
