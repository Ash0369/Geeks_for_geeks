class Solution {
  public:
    string solve(int A, int B) {
        if(A%2==0 && B%2==0)
        {
            return "He";
        }
        else if(A%2!=0 && B%2!=0)
        {
            return "She";
        }
        return "Punished";
    }
};
