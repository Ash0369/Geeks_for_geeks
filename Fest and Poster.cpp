#define ll long long
class Solution 
{
  public:
    long long minimumTime(int N, int NUM, vector<int> &time) 
    {
        int n=N;
        int p=NUM;
        
        sort(time.begin(),time.end());
        
        ll int left=1;
        ll int right=1e18;
        ll int ans=right;
        
        
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            
            ll int make=0;
            
            for(auto x:time)
            {
                ll int t=mid/x;
                make+=t;
            }
            if(make>=p)
            {
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
