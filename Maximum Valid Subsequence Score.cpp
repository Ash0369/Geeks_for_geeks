class Solution 
{
  public:
    int maxScoreSubseq(int n, vector<int> &arr)
    {
        int mx=INT_MIN;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,arr[i]);
            if(arr[i]>=0)
            {
                mp[arr[i]-i]+=arr[i];
            }
        }
        if(mp.size()==0)
        {
            return mx;
        }
        int ans=-1;
        for(auto x:mp)
        {
            ans=max(ans,x.second);
        }
        return ans;
    }
};
