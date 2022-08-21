class Solution
{
    public:
    vector<int> rightView(Node *root)
    {
       vector<int>result;
       queue<Node*>q;
       q.push(root);
       q.push(NULL);
       while(!q.empty() && !( q.front()==NULL && q.size()==1))
       {
            Node *temp=q.front();
            q.pop();
            
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }

            if(q.front()==NULL)
            {
                result.push_back(temp->data);
                q.pop();
                q.push(NULL);
            }

       }
        return result;
    }
};
