class Solution{
    public:
    int distributeCandies(int n, vector<int> &arr)
    {
        int to=1e9;
        for(int i=2;i<=1000;i++)
        {
            int t=0;
            for(auto x:arr)
            {
                if((x%i)==0)
                {
                    
                }
                else
                {
                    int d=x/i;
                    d++;
                    int need=d*i;
                    t+=need-x;
                }
            }
            to=min(to,t);
        }
        return to;
    }
};
