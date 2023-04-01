#define ll long long
class Solution 
{
  public:
    long long int minOperations(int N) 
    {
        int n=N;
        if(n%2==0)
        {
            return 1LL*n*n/4;
        }
        return 1LL*(n/2)*((n/2)+1);
    }
};
