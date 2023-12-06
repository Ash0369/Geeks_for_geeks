class Solution {
  public:
    int countX(int L, int R, int X) {
        int s=0;
        for(int i=L+1;i<R;i++)
        {
            int j=i;
            while(j>0)
            {
                if((j%10)==X)
                {
                    s++;
                }
                j=j/10;
            }
        }
        return s;
    }
};
