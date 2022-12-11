class Solution 
{
  public:
    bool canPair(vector<int> nums, int k) 
    {
        map<int,int>mp;
        for(auto x:nums)
        {
            //cout<<(x%k)<<"  ";
            mp[x%k]++;
        }
        bool res=true;
        for(auto x:mp)
        {
            int need=x.second;
            if(need==0)
            {
                continue;
            }
            int val=x.first;
            int b=k-val;
            if(b==k)
            {
                b=0;
            }
            if(val==b)
            {
                if(need%2!=0)
                {
                    res=false;
                }
                continue;
            }
            mp[val]=0;
            if(mp.find(b)!=mp.end() && mp[b]>=need)
            {
                mp[b]=mp[b]-need;
            }
            else
            {
                res=false;
                break;
            }
        }
        return res;
    }
};
