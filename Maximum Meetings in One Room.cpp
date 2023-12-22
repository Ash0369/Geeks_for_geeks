bool cmp(vector<int>&v,vector<int>&p)
{
    if(v[1]<p[1])
    {
        return true;
    }
    return false;
}
class Solution{
public:
    vector<int> maxMeetings(int n,vector<int> &s,vector<int> &f)
    {
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({s[i],f[i],i});
        }
        sort(v.begin(),v.end(),cmp);
        int av=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int start=v[i][0];
            if(start<av)
            {
                continue;
            }
            int end=v[i][1];
            av=end+1;
            ans.push_back(v[i][2]+1);
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
