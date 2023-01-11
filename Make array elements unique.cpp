class Solution 
{
  public:
    long long int minIncrements(vector<int> arr, int N) 
    {
        #define ll long long
        ll int s=0;
        map<ll int,ll int>mp;
        for(auto x:arr)
        {
            s=s+x;
            mp[x]++;
        }
        ll int need=0;
        for(auto x:mp)
        {
            ll int ele=x.first;
            ll int ocu=x.second;
            if(ocu>1)
            {
                mp[ele+1]+=ocu-1;
                need+=ocu-1;
            }
        }
        return need;
    }
};
