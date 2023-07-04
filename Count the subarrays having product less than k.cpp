class Solution
{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) 
    {
        #define ll long long
        ll int curr=1;
        int left=0;
        ll int ans=0;
        for(int i=0;i<n;i++)
        {
            curr=curr*a[i];
            while(curr>=k)
            {
                curr=curr/a[left];
                left++;
            }
            //cout<<curr<<endl;
            ans=ans+max(0,i-left+1);
        }
        return max(0LL,ans);
    }
};
