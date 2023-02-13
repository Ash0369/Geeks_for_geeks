class Solution 
{
  public:
    int setBits(int N) 
    {
        return __builtin_popcount(N);
    }
};
