//Method-1 : 

int counter=0;
int result;
void traversal(Node* root,int k)
{
    if(root==NULL)
    {
        return;
    }

    traversal(root->right,k);
    
    counter++;
    if(counter==k)
    {
        result=root->data;
    }
    traversal(root->left,k);
}
class Solution
{
    public:
    int kthLargest(Node *root, int k)
    {
        counter=0;
        traversal(root,k);
        return result;
    }
};

//Method-2 : 

int large(Node *root,int &k)
{
    if(root==NULL)
    {
        return -1;
    }
    int a=large(root->right,k);
    if(a!=-1)
    {
        return a;
    }
    k--;
    if(k==0)
    {
        return root->data;
    }
    return large(root->left,k);
}

class Solution 
{
  public:
    
    int kthLargest(Node *root, int k)
    {
        return large(root,k);
    }
};

