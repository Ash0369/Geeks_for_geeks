#define ll long long
class Solution 
{
  public:
    long long findLevel(long long N) 
    {
        ll int n=N;
        if(n==1)
        {
            return 1;
        }
        ll int ans=1;
        ll int curr=1;
        ll int level=2;
        
        while(ans<=n)
        {
           
            curr=curr*level;
            //cout<<curr<<endl;
            ans=ans+curr;
            if(ans==n)
            {
                return level;
            }
            level++;
        }
        return level-1;
    }
};
