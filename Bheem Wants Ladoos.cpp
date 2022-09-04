int child_sum=0;
void find_in_child(Node *root,int k)
{
    if(k<0 || root==NULL)
    {
        return;
    }
    child_sum=child_sum+root->data;
    find_in_child(root->left,k-1);
    find_in_child(root->right,k-1);
}
int find(Node* root, int home, int k)
{
    if(root==NULL)
    {
        return -1;
    }
    
    if(root->data==home)
    {
        find_in_child(root,k);
        return 0;
    }
    
    
    int r=find(root->right,home,k);
    if(r!=-1)
    {
        if(k-r-2>=-1)
        {
            child_sum=child_sum+root->data;
        }
        
        find_in_child(root->left,k-r-2);
        
        return r+1;
    }
    int l=find(root->left,home,k);
    if(l!=-1)
    {
        if(k-l-2>=-1)
        {
            child_sum=child_sum+root->data;
        }
        
        find_in_child(root->right,k-l-2);
        
        return l+1;
    }
    
    return -1;
}
class Solution
{

    public:
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        child_sum=0;
        find(root,home,k);
        return child_sum;
    }


};
