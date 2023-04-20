Node* dfs(Node *root,int home)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==home)
    {
        return root;
    }
    Node *a=dfs(root->left,home);
    Node *b=dfs(root->right,home);
    
    if(a==NULL)
    {
        return b;
    }
    return a;
}
class Solution
{

    public:
    int ladoos(Node* root, int home, int k)
    {
        map<Node*,Node*>parent;
        map<Node*,bool>mp;
        
        Node *f=dfs(root,home);
        queue<Node *>q;
        q.push(root);
        
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            if(node->left)
            {
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        
        q.push(f);
        int ans=0;
       // k++;
       mp[f]=1;
        while(k>=0)
        {
            int sz=q.size();
            while(sz--)
            {
               ans+=q.front()->data;
              // cout<<q.front()->data<<endl;
                auto node=q.front();
                q.pop();
                
                if(node->left && mp.find(node->left)==mp.end())
                {
                    q.push(node->left);
                    mp[node->left]=1;
                }
                if(node->right && mp.find(node->right)==mp.end())
                {
                    q.push(node->right);
                    mp[node->right]=1;
                }
                if(parent.find(node)!=parent.end() && mp[parent[node]]==0)
                {
                    q.push(parent[node]);
                    mp[parent[node]]=1;
                }
                
            }
            k--;
        }
        return ans;
        
    }


};
