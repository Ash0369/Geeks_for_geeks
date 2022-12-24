#define ll long long
class Solution
{
  public:
  long long int wineSelling(vector<int>&arr, int n)
  {
      vector<int>st;
      for(int i=0;i<n;i++)
      {
          if(arr[i]>0)
          {
              st.push_back(i);
          }
      }
      ll int ans=0;
      int iter=0;
      for(int i=0;i<n;i++)
      {
          if(arr[i]<0)
          {
              while(arr[i]<0)
              {
                  int ind=st[iter];
                  int val=arr[ind];
                  if(val==abs(arr[i]))
                  {
                      ans+=(abs(i-ind)*val);
                      arr[i]=0;
                      arr[ind]=0;
                      iter++;
                  }
                  else if(val>abs(arr[i]))
                  {
                      ans+=abs(i-ind)*abs(arr[i]);
                      arr[ind]=arr[ind]-abs(arr[i]);
                      arr[i]=0;
                  }
                  else
                  {
                      ans+=abs(i-ind)*arr[ind];
                      arr[i]=arr[i]+val;
                      arr[ind]=0;
                      iter++;
                  }
              }
          }
      }
      return ans;
  }
};
