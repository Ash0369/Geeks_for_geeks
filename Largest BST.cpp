vector<int> check(Node *root)
{
    if(root==NULL)
    {
        return {0,INT_MAX,INT_MIN}; // size,minimum value , maximimum value
    }
    
    auto l=check(root->left);
    auto r=check(root->right);
    vector<int>res;
    if(root->data>l[2]  && root->data<r[1])
    {
        res.push_back(l[0]+r[0]+1);
        res.push_back(min(l[1],root->data));
        res.push_back(max(r[2],root->data));
        
        return res;
    }
    
    res.push_back(max(l[0],r[0]));
    res.push_back(INT_MIN);
    res.push_back(INT_MAX);
    
    return res;
}
class Solution
{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return check(root)[0];
    }
};
