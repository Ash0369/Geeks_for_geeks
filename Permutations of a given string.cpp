void permute(string s,vector<string>&vec,string curr,vector<int>&visited,set<string>&exist)
{
    if(curr.size()==s.size() && exist.find(curr)==exist.end())
    {
        vec.push_back(curr);
        exist.insert(curr);
        return;
    }
    for(int i=0;i<s.length();i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            curr.push_back(s[i]);
            permute(s,vec,curr,visited,exist);
            curr.pop_back();
            visited[i]=0;
        }
    }
}
class Solution
{
	public:
		vector<string>find_permutation(string s)
		{
		    vector<string>vec;
		    vector<int>visited(s.size()+1,0);
		    set<string>st;
		    permute(s,vec,"",visited,st);
		    sort(vec.begin(),vec.end());
		    return vec;
		}
};
