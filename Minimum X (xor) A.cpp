class Solution 
{
  public:
    int minVal(int a, int b) 
    {
        int seet=__builtin_popcount(b);
        set<int>st;
        int cnt=0;
        while(a>0)
        {
            int t=a&1;
            if(t==1)
            {
                st.insert(cnt);
            }
            cnt++;
            a=a>>1;
        }
        long long int ans=0;
        int pos=0;
        for(auto x=st.rbegin();x!=st.rend();x++)
        {
            if(seet>0)
            {
                ans+=pow(2,(*x));
                seet--;
            }
        }
        while(seet>0)
        {
            if(st.find(pos)==st.end())
            {
                ans+=pow(2,pos);
                seet--;
            }
            pos++;
        }
        return ans;
    }
};
