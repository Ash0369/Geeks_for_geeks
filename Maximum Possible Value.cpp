#define ll long long
class Solution 
{
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) 
    {
        int n=N;
        ll int ans=0;
        int mn=1e9;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(B[i]<=1)
            {
                continue;
            }
            cnt+=B[i]/2;
            mn=min(mn,A[i]);
            ans+=(B[i]/2)*(A[i]*2);
        }
        if(cnt%2!=0)
        {
            ans=ans-(2*mn);
        }
        return ans;
    }
};
