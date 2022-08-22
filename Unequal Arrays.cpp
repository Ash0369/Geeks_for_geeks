class Solution 
{
  public:
    #define ll long long int
    long long solve(int N, vector<int> &A, vector<int> &B) 
    {
        ll sum1=0;
        ll sum2=0;
        ll diff=0;
        vector<int>aeven;
        vector<int>beven;
        vector<int>aodd;
        vector<int>bodd;
        
        for(auto x:A)
        {
            if(x%2==0)
            {
                aeven.push_back(x);
            }
            else
            {
                aodd.push_back(x);
            }
            sum1=sum1+x;
        }
        for(auto x:B)
        {
            if(x%2==0)
            {
                beven.push_back(x);
            }
            else
            {
                bodd.push_back(x);
            }
            sum2=sum2+x;
        }
        
        sort(aeven.begin(),aeven.end());
        sort(beven.begin(),beven.end());
        sort(aodd.begin(),aodd.end());
        sort(bodd.begin(),bodd.end());
        
        if(sum1!=sum2)
        {
            return -1;
        }
        
        if(aeven.size()!=beven.size())
        {
            return -1;
        }
        if(aodd.size()!=bodd.size())
        {
            return -1;
        }
        
        for(int i=0;i<aeven.size();i++)
        {
            diff=diff+abs(aeven[i]-beven[i]);
        }
        for(int i=0;i<aodd.size();i++)
        {
            diff=diff+abs(aodd[i]-bodd[i]);
        }
        
        return diff/4;
    }
};
