bool check(int n)
{
    set<int>st;
    while(st.find(n)==st.end())
    {
        st.insert(n);
        int sum=0;
        while(n>0)
        {
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        if(sum==1)
        {
            return true;
        }
        n=sum;
    }
    return false;
}
class Solution
{
public:
    int nextHappy(int N)
    {
        N++;
        while(1)
        {
            if(check(N))
            {
                return N;
            }
            N++;
        }
    }
};
