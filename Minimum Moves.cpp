class Solution 
{
  public:
    long long minimumMoves(int n, vector<int> &a, vector<int> &b) 
    {
        #define ll long long
        vector<int>diff(n,0);
        for(int i=0;i<n;i++)
        {
            diff[i]=b[i]-a[i];
        }
        
        int prev=0;
        int sign=diff[0]>0 ? -1 : 1;
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            if(diff[i]>0 && sign==-1)
            {
                ans+=abs(diff[i]);
                sign=1;
                
            }
            else if(diff[i]<0 && sign==1)
            {
                ans+=abs(diff[i]);
                sign=-1;
            }
            else
            {
                if(abs(diff[i])>prev)
                {
                    ans+=abs(diff[i])-prev;
                }
            }
            
            prev=abs(diff[i]);
        }
        return ans;
    }
};
