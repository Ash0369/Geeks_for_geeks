class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        vector<int>vec(n+1,0);
        vec[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(vec[i]==0)
            {
                int j=i*2;
                for(;j<=n;j=j+i)
                {
                    vec[j]=1;
                }
            }
        }
        vector<int>res;
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]==0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
