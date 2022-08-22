class Solution 
{
  public:
    int getMaximum(int N, vector<int> &arr) 
    {
        long long int sum=0;
        for(auto x:arr)
        {
            sum=sum+x;
        }
        for(long long int i=N;i>=1;i--)
        {
            if(sum%i==0)
            {
                return i;
            }
        }
    }
};
