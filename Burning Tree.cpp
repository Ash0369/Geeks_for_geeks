Node *find_node(Node *root,int target)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==target)
    {
        return root;
    }
    Node *l=find_node(root->left,target);
    if(l)
    {
        return l;
    }
    Node *r=find_node(root->right,target);
    return r;
    
}

int depth(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int a=1+depth(root->left);
    int b=1+depth(root->right);

    return max(a,b);
}

class Solution
{
    public:
    int minTime(Node* root, int target) 
    {
        if(root==NULL)
        {
            return 0;
        }
        map<Node*,Node*>parent;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node *r=q.front();
            q.pop();
            if(r->left)
            {
                parent[r->left]=r;
                q.push(r->left);
            }
            if(r->right)
            {
                parent[r->right]=r;
                q.push(r->right);
            }
        }
        
        map<Node*,int>visited;
        Node *pos=find_node(root,target);
        q.push(pos);
        int time=0;
        while(!q.empty())
        {
            int k=q.size();
           
            time++;
            for(int i=0;i<k;i++)
            {
                Node *r=q.front();
                q.pop();
                if(visited[r]==0)
                {
                    if(r->left && visited[r]==0 )
                    {
                        q.push(r->left);
                    }
                    if(r->right && visited[r]==0)
                    {
                        q.push(r->right);
                    }
                    if(parent.find(r)!=parent.end() && visited[r]==0)
                    {
                        q.push(parent[r]);
                    }
                    visited[r]=1;
                }
            }
        }
        if(time==1)
        {
            return 0;
        }
        return time-2; // Because it will count time for 0th as well as last second
    }
};
