class Solution 
{
  public:
    int leastInterval(int N, int K, vector<char> &tasks) 
    {
        int n=N;
        int k=K;
        
        map<char,int>mp;
        for(auto x:tasks)
        {
            mp[x]++;
        }
        int cnt=0;
        int mx=0;
        int tot=0;
        for(auto x:mp)
        {
            mx=max(x.second,mx);
            tot=tot+x.second;
        }
        for(auto x:mp)
        {
            if(x.second==mx)
            {
                cnt++;
            }
        }
        return max(n,cnt+(mx-1)*(k+1));
    }
};
