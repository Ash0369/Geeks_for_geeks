set<string>dp;
vector<int>edges;

void dfs(string &node,int k)
{
    for(int i=0;i<k;i++)
    {
        string temp=node;
        temp.push_back(i+'0');
        if(dp.find(temp)==dp.end())
        {
            dp.insert(temp);
            string t=temp.substr(1);
            dfs(t,k);
            edges.push_back(i);
        }
    }
}
class Solution
{
public:
    string findString(int n, int k) 
    {
        dp.clear();
        edges.clear();
        
        string start=string(n-1,'0');
        dfs(start,k);
        
        int l=pow(k,n);
        string ans;
        
        for(int i=0;i<l;i++)
        {
            ans.push_back(edges[i]+'0');
        }
        ans+=start;
        return ans;
    }
};
