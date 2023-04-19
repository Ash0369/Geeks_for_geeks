class Solution 
{
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &penalty) 
    {
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])==mp.end())
            {
                ans++;
                mp[arr[i]]=1;
            }
            else
            {
                ans+=penalty[arr[i]-1];
            }
            //cout<<ans<<endl;
        }
        return ans-1;
    }
};
