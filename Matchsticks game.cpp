#define ll long long
class Solution 
{
  public:
    int matchGame(long long N) 
    {
        ll int n=N;
        if(n%5==0)
        {
            return -1;
        }
        return (n%5);
    }
};
