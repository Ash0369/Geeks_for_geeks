#define ll long long
class Solution 
{
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) 
    {
        ll int sum1=0;
        ll int sum2=0;
        int n=N;
        
        for(auto x:A)
        {
            sum1+=x;
        }
        for(auto x:B)
        {
            sum2+=x;
        }
        if(sum1!=sum2)
        {
            return -1;
        }
        vector<int>ao;
        vector<int>ae;
        vector<int>bo;
        vector<int>be;
        
        for(auto x:A)
        {
            if(x%2==0)
            {
                ae.push_back(x);
            }
            if(x%2!=0)
            {
                ao.push_back(x);
            }
        }
        for(auto x:B)
        {
            if(x%2==0)
            {
                be.push_back(x);
            }
            if(x%2!=0)
            {
                bo.push_back(x);
            }
        }
        sort(ao.begin(),ao.end());
        sort(ae.begin(),ae.end());
        sort(bo.begin(),bo.end());
        sort(be.begin(),be.end());
        if(ao.size()!=bo.size() || ae.size()!=be.size())
        {
            return -1;
        }
        ll int ans=0;
        for(int i=0;i<ae.size();i++)
        {
            ans+=abs(ae[i]-be[i])/2;
        }
        for(int i=0;i<ao.size();i++)
        {
            ans+=abs(ao[i]-bo[i])/2;
        }
        return ans/2;
       
    }
};
