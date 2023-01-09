class Solution 
{
  public:
    int solve(int N, vector<int> A) 
    {
        int n=N;
        int carry=1;
        int ans=1;
        for(int i=n-1;i>=0;i--)
        {
            A[i]+=carry;
            if(A[i]==10)
            {
                carry=1;
            }
            else
            {
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};
