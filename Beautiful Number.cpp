class Solution 
{
  public:
    bool beautifulNumber(int n) 
    {
        set<int>st;
        while(st.find(n)==st.end())
        {
            if(n==1)
            {
                return true;
            }
            st.insert(n);
            int nx=0;
            while(n>0)
            {
                int d=n%10;
                nx+=d*d;
                n=n/10;
            }
            n=nx;
        }
        return false;
    }
};
