#define ll long long

//let positon 0 represent last index minimim and position 1 represent last index maximum
ll int dfs(int index,vector<int>&types,int position,vector<int>&mn,vector<int>&mx,vector<vector<ll int>>&dp)
{
    ll int curr=0;
    if(index-1>=0)
    {
        if(position==0)
        {
            curr=mn[types[index-1]];
        }
        else
        {
            curr=mx[types[index-1]];
        }
    }
    if(index==types.size())
    {
        return abs(curr);
    }
    
    int point=types[index];
    if(dp[point][position]!=-1)
    {
        return dp[point][position];
    }
    //either to minimum first or maximum first
    
    ll int ans1=abs(curr-mn[point])+abs(mx[point]-mn[point])+dfs(index+1,types,1,mn,mx,dp);
    ll int ans2=abs(curr-mx[point])+abs(mx[point]-mn[point])+dfs(index+1,types,0,mn,mx,dp);

    return dp[point][position]=min(ans1,ans2);
}

class Solution 
{
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) 
    {
        vector<int>mn(100005,INT_MAX);
        vector<int>mx(100005,INT_MIN);
        for(int i=0;i<n;i++)
        {
            mn[types[i]]=min(mn[types[i]],locations[i]);
            mx[types[i]]=max(mx[types[i]],locations[i]);
        }
        sort(types.begin(),types.end());
        vector<int>t;
        for(auto x:types)
        {
            if(t.empty())
            {
                t.push_back(x);
            }
            else if(t.back()!=x)
            {
                t.push_back(x);
            }
            
        }
        vector<vector<ll int>>dp(t.back()+2,vector<ll int>(2,-1));
        return dfs(0,t,0,mn,mx,dp);
    }
};
