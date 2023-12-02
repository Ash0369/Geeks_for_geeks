vector<int>v1;
vector<int>v2;

void dfs1(Node *root1)
{
    if(root1==NULL)
    {
        return;
    }
    
    dfs1(root1->left);
    v1.push_back(root1->data);
    dfs1(root1->right);
}

void dfs2(Node *root2)
{
    if(root2==NULL)
    {
        return;
    }
    
    dfs2(root2->left);
    v2.push_back(root2->data);
    dfs2(root2->right);
}

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x1)
    {
        v1.clear();
        v2.clear();
        dfs1(root1);
        dfs2(root2);
        
        int ans=0;
        
        for(int i=0;i<v1.size();i++)
        {
            int curr=v1[i];
            int need=x1-curr;
            auto lb=lower_bound(v2.begin(),v2.end(),need);
            if(lb!=v2.end()){
                if((*lb)==need)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
