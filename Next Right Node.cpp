class Solution
{
public:
    Node *nextRight(Node *root, int key)
    {
        queue<Node*>q;
        q.push(root);
        vector<vector<Node*>>vec;
        vec.push_back({root});
        Node *n=new Node(-1);
        while(!q.empty())
        {
            int a=q.size();
            vector<Node*>res;
            for(int i=0;i<a;i++)
            {
                Node *temp=q.front();
                q.pop();
                if(temp->left)
                {
                    res.push_back(temp->left);
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    res.push_back(temp->right);
                    q.push(temp->right);
                }
            }
            vec.push_back(res);
        }
        for(auto x:vec)
        {
            for(int i=0;i<x.size();i++)
            {
                if(x[i]->data==key)
                {
                    if(i!=x.size()-1)
                    {
                        return x[i+1];
                    }
                    else
                    {
                        return n;
                    }
                }
            }
        }
        return n;
    }
};
