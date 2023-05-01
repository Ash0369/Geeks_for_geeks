vector<pair<int,int>>info;

pair<int,int> dfs(Node *root)
{
    if(root==NULL)
    {
        return {0,0};
    }
    int ans=0;
    int sz=0;
    for(auto x:root->children)
    {
        auto p=dfs(x);
        ans+=p.first;
        sz+=p.second;
    }
    ans+=root->data;
    sz=1+sz;
    info.push_back({ans,sz});
    return {ans,sz};
}
class Solution
{
public:
    int duplicateSubtreeNaryTree(Node *root)
    {
        int ans=0;
        info.clear();
        dfs(root);
        sort(info.begin(),info.end());
        for(int i=1;i<info.size();i++)
        {
            if(info[i].first==info[i-1].first && info[i].second==info[i-1].second)
            {
                ans++;
                while(i<info.size() && info[i].first==info[i-1].first && info[i].second==info[i-1].second)
                {
                    i++;
                }
                i--;
            }
        }
        return ans;
    }
};
