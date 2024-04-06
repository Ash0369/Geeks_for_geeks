#define ll long long
class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) 
    {
       return (n/2)+1;
    }
};
