int cal(vector<int>&a,int X)
{
     map<int,int>mp;
     for(auto x:a)
     {
         mp[x]++;
     }
     int ans=0;
     for(auto x:mp)
     {
         if(x.second<X)
         {
             ans+=abs(x.second);
         }
         else{
             ans+=abs(x.second-X);
         }
     }
      return ans;
}
class Solution
{
  public:
  int stableArray(vector<int>& a)
  {
      int n=a.size();
      map<int,int>mp;
      for(auto x:a)
      {
          mp[x]++;
      }
      int tot=0;
      int z=0;
      for(auto x:mp)
      {
          tot+=x.second;
          z++;
      }
      int ans=n-1;
      int avg=tot/z;
      for(int i=avg-2;i<=avg+2;i++)
      {
          ans=min(ans,cal(a,i));
      }
      
      return ans;
  }
};
