#define ll long long
class Solution 
{
  public:
    int minimumInteger(int N, vector<int> &A) 
    {
        int n=N;
        ll int sum=0;
        for(auto x:A)
        {
            sum=sum+x;
        }
        sort(A.begin(),A.end());
        ll int num=(sum/n)+((sum%n)!=0);
        auto index=lower_bound(A.begin(),A.end(),num)-A.begin();
        return A[index];
        
    }
};
