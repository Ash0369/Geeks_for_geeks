//Method-1 : 

class Solution
{
  public:
  int smallestSumSubarray(vector<int>& a)
  {
      int n=a.size();
      for(int i=0;i<n;i++)
      {
          a[i]=a[i]*(-1);
      }
      int ans=INT_MIN;
      int curr=0;
      for(auto x:a)
      {
          curr+=x;
          if(curr>ans)
          {
              ans=curr;
          }
          if(curr<0)
          {
              curr=0;
          }
      }
      return -1*ans;
  }
};

//Method-2 : 


class Solution{
  public:
  int smallestSumSubarray(vector<int>& a)
  {
      int ans=INT_MIN;
      int curr=0;
      for(auto x:a)
      {
          x=x*(-1);
          curr+=x;
          if(curr>ans)
          {
              ans=curr;
          }
          if(curr<0)
          {
              curr=0;
          }
      }
      return -1*ans;
  }
};
