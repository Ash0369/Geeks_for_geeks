int ans;
int nde;
void gcd(Node *root)
{
    //cout<<nde<<endl;
    if(root==NULL)
    {
        return;
    }
    if(root->left!=NULL && root->right!=NULL)
    {
        int a=__gcd(root->left->data,root->right->data);
        if(a>ans)
        {
            ans=a;
            nde=root->data;
        }
        else if(a==ans)
        {
            nde=max(nde,root->data);
        }
    }
    gcd(root->left);
    gcd(root->right);
}
class Solution
{
public:
    int maxGCD( Node* root)
    {
        ans=-1;
        nde=0;
        gcd(root);
        if(ans==-1)
        {
            return 0;
        }
        return nde;
    }
};
