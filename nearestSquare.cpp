#define ll long long
class Solution{
  public:
  long long nearestSquare(long long n)
  {
      ll int p=sqrt(n);
      
      ll int ans=0;
      ll int d=1e18;
      
      for(ll int i=max(0LL,p-5);i<=p+5;i++)
      {
          ll int res=i*i;
          if((abs(n-res))<=d)
          {
              if(abs(n-res)==d)
              {
                  ans=max(ans,res);
                  continue;
              }
              d=abs(n-res);
              ans=res;
              
          }
      }
      return ans;
  }
};
