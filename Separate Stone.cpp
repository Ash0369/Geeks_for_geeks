class Solution 
{
  public:
    int separateStones(int N, int K, vector<int> &arr) 
    {
        int cnt1=0;
        int cnt2=0;
        for(auto x:arr)
        {
            if(x==1)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }
        int ans=0;
        ans=(cnt1+K-1)/K;
        ans+=(cnt2+K-1)/K;
        return ans;
    }
};
