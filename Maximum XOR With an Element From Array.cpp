#define ll long long
struct Node
{
    Node *links[2];
    bool if_exist(int a)
    {
        if(links[a]==NULL)
        {
            return false;
        }
        return true;
    }
    Node* get(int a)
    {
        return links[a];
    }
    void put(int a,Node *node)
    {
        links[a]=node;
    }
};
class Trie
{
    public:
    Node *root;
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node *node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->if_exist(bit)==false)
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    ll int get_max(int num)
    {
        Node *node=root;
        ll int maxnum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->if_exist(1-bit)==false)
            {
                node=node->get(bit);
            }
            else
            {
                maxnum=maxnum|(1<<i);
                node=node->get(1-bit);
            }
            
        }
        return maxnum;
    }
};
bool cmp(vector<int>&vec1,vector<int>&vec2)
{
    if(vec1[1]<vec2[1])
    {
        return true;
    }
    return false;
}

class Solution 
{
  public:
    vector<long long> maximumXor(int N, int Q, vector<int> &arr,
                                 vector<vector<int>> &queries) 
    {
        Trie trie;
        int q=Q;
        for(int i=0;i<q;i++)
        {
            queries[i].push_back(i);
        }
        vector<ll int>ans(q,-1);
        sort(queries.begin(),queries.end(),cmp);
        sort(arr.begin(),arr.end());
        int index=0;
        int n=N;
        for(int i=0;i<q;i++)
        {
            while(index<n && arr[index]<=queries[i][1])
            {
                trie.insert(arr[index]);
                index++;
            }
            if(index==0)
            {
                ans[queries[i][2]]=-1;
            }
            else
            {
                ans[queries[i][2]]=trie.get_max(queries[i][0]);
            }
        }
        return ans;
    }
};
