bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[1]>v2[1])
    {
        return true;
    }
    return false;
}
class Solution
{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k)
    {
        sort(intervals.begin(),intervals.end(),cmp);
        map<int,int>mp;
        for(auto x:intervals)
        {
            mp[x[0]]++;
            mp[x[1]+1]--;
        }
        int ans=-1;
        int curr=0;
        for(auto x:mp)
        {
            curr+=x.second;
            if(curr>=k)
            {
                ans=x.first;
            }
            else if(curr-x.second>=k)
            {
                ans=x.first-1;
            }
        }
        return ans;
    }
};
