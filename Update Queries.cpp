class Solution
{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            int n=N;
            int q=Q;
            vector<int>vec(n,0);
            vector<vector<int>>u=U;
            
            vector<vector<int>>orr(n,vector<int>(30,0));
            for(auto x:u)
            {
                int l=x[0]-1;
                int r=x[1];
                int op=x[2];
                int bit=0;
                while(op>0)
                {
                    int b=(op&1);
                    orr[l][bit]+=b;
                    if(r<n)
                    {
                        orr[r][bit]-=b;
                    }
                    
                    op=op>>1;
                    bit++;
                }
            }
            vector<int>curr(30,0);
            for(int i=0;i<n;i++)
            {
                long long num=0;
                int wait=0;
                for(int j=0;j<30;j++)
                {
                    curr[j]+=orr[i][j];
                    if(curr[j]>0)
                    {
                        num=num+(1<<j);
                        wait=0;
                    }
                    else
                    {
                        wait++;
                    }
                }
                vec[i]=num;
            }
            return vec;
        }
};
