#define ll long long
#define mod 1000000007;

ll int dp[1005][1LL<<15];
ll int dfs(int n,int index,int mp,vector<vector<int>>&store,vector<int>&prime)
{
    if(index==n)
    {
       return mp>0;
    }
    if(dp[index][mp]!=-1)
    {
        return dp[index][mp];
    }
    ll int ans1=dfs(n,index+1,mp,store,prime);
    if(store[index].size()==0)
    {
        return dp[index][mp]=ans1%mod;
    }
    ll int ans2=0;
    ll int mp2=mp;
    for(auto x:store[index])
    {
        if(x==1)
        {
            continue;
        }
        if(mp2&(1LL<<x))
        {
            return dp[index][mp]=ans1%mod;
        }
        mp2=mp2|(1LL<<x);
    }
    
    ans2=dfs(n,index+1,mp2,store,prime);
    

    return dp[index][mp]=(ans1+ans2)%mod;
}
class Solution 
{
  public:
    int primeSubsets(int n, vector<int> &Arr) 
    {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>mp(n+1);
        vector<int>prime(31,0);
        prime[2]=2;
        prime[3]=3;
        prime[5]=4;
        prime[7]=5;
        prime[11]=6;
        prime[13]=7;
        prime[17]=8;
        prime[19]=9;
        prime[23]=10;
        prime[29]=11;

        
        for(int j=0;j<n;j++)
        {
            int ele=Arr[j];
            if(ele==1)
            {
                mp[j].push_back(1);
                continue;
            }
            for(int i=2;i*i<=ele;i++)
            {
                int c=0;
                while(ele%i==0 && ele>1)
                {
                    c++;
                    ele=ele/i;
                }
                if(c==1)
                {
                    mp[j].push_back(prime[i]);
                }
                else if(c>1)
                {
                    mp[j]={};
                    ele=1;
                    break;
                }
            }
            
            if(ele>1)
            {
                mp[j].push_back(prime[ele]);
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<" ";
        //     for(auto y:mp[i])
        //     {
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return dfs(n,0,0,mp,prime);
    }
};
