#define ll long long
class Solution
{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) 
    {
        queue<Node*>q;
        q.push(root);
        ll int ans=root->data;
        while(!q.empty())
        {
            int sz=q.size();
            ll int curr=0;
            while(sz--)
            {
                auto nde=q.front();
                q.pop();
                curr=curr+nde->data;
                if(nde->left)
                {
                    q.push(nde->left);
                }
                if(nde->right)
                {
                    q.push(nde->right);
                }
                
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};
