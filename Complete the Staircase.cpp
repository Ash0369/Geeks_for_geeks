class Solution {
  public:
  #define ll long long 
    int completeRows(int n) 
    {
        //1 + 2 +3 +4 +5
        ll int left=1;
        ll int right=1e6;
        ll int ans=1;
        while(left<=right)
        {
            ll int mid=(left+right)/2;
            ll int req=mid*(mid+1)/2;
            if(req>n)
            {
                right=mid-1;
            }
            else
            {
                ans=mid;
                left=mid+1;
            }
        }
        return ans;
    }
};
