class Solution 
{
  public:
    bool lemonadeChange(int N, vector<int> &bills) 
    {
        int n=N;
        int five=0;
        int ten=0;
        int tw=0;
        for(auto x:bills)
        {
            if(x==5)
            {
                five++;
            }
            else if(x==10)
            {
                ten++;
                if(five==0)
                {
                    return false;
                }
                five--;
            }
            else
            {
                tw++;
                if(ten>0 && five>0)
                {
                    ten--;
                    five--;
                }
                else if(five>2)
                {
                    five=five-3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
