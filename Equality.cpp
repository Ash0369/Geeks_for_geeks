class Solution {
  public:
    int equality(int A, int B) {
        if(B>A)
        {
            if(A%2==0)
            {
                if(B%2==0)
                {
                    return true;
                }
            }
            else{
                A++;
                if(A==B)
                {
                    return true;
                }
                if(B%2==0)
                {
                    return true;
                }
            }
        }
        else if(B==A)
        {
            return true;
        }
        return false;
    }
};
