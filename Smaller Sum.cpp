#define ll long long

bool cmp(vector<int>&v1,vector<int>&v2)
{
    if(v1[1]<v2[1])
    {
        return true;
    }
    return false;
}

class Solution
{
public:
    vector<long long> smallerSum(int n,vector<int> &arr)
    {
        vector<vector<int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({i,arr[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<ll int>ans(n);
        int i=0;
        ll int tot=0;
        for(int i=0;i<n;i++)
        {
            int val=vec[i][1];
            ans[vec[i][0]]=tot;
            tot+=val;
            i++;
            while(i<n && vec[i][1]==val)
            {
                ans[vec[i][0]]=ans[vec[i-1][0]];
                i++;
                tot=tot+val;
            }
            i--;
        }
        return ans;
    }
};
