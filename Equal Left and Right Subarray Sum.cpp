class Solution 
{
    #define ll long long
  public:
    int equalSum(int N, vector<int> &A) 
    {
        int n=N;
        ll int prev=accumulate(A.begin(),A.end(),0LL);
        ll int sum=0;
        int ans=-2;
        for(int i=n-1;i>=0;i--)
        {
            prev=prev-A[i];
            if(prev==sum)
            {
                ans=i;
            }
            sum=sum+A[i];
        }
        
        return ans+1;
    }
};
