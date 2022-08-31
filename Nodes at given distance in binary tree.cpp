//Method-1 : 

vector<int>res;

void find_in_child(Node *root,int k)
{
    if(k<0)
    {
        return;
    }
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        res.push_back(root->data);
        return;
    }
    find_in_child(root->left,k-1);
    find_in_child(root->right,k-1);
}
int distance(Node *root,int target,int k)
{
    if(root==NULL)
    {
        return -1*(1e+7);
    }
    if(root->data==target)
    {
        find_in_child(root,k);
        return 0;
    }
    int l=distance(root->left,target,k);
    if(l>=0)
    {
        find_in_child(root->right,k-l-2);
        if(k-l-2==-1)
        {
            res.push_back(root->data);
        }
        
    }
    int r=distance(root->right,target,k);
    if(r>=0)
    {
        find_in_child(root->left,k-r-2);
        if(k-r-2==-1)
        {
            res.push_back(root->data);
        }
    }
    
    return 1+max(l,r);
}
class Solution
{
private:

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        res.clear();
        distance(root,target,k);
        sort(res.begin(),res.end());
        return res;
    }
};


//Method-2 : 

vector<int>res;

void find_in_child(Node *root,int k)
{
    if(k<0)
    {
        return;
    }
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        res.push_back(root->data);
        return;
    }
    find_in_child(root->left,k-1);
    find_in_child(root->right,k-1);
}
int distance(Node *root,int target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==target)
    {
        find_in_child(root,k);
        return 0;
    }
    int l=distance(root->left,target,k);
    if(l>=0)
    {
        find_in_child(root->right,k-l-2);
        if(k-l-2==-1)
        {
            res.push_back(root->data);
        }
        return l+1;
        
    }
    int r=distance(root->right,target,k);
    if(r>=0)
    {
        find_in_child(root->left,k-r-2);
        if(k-r-2==-1)
        {
            res.push_back(root->data);
        }
        return r+1;
    }
    
    return -1;
}
