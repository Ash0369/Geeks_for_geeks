class Solution{
  public:
  bool areIsomorphic(string s1, string s2)
  {
     // return true;
      map<char,char>mp;
      map<char,char>mp1;
      int z=s1.size();
      if(s2.size()!=z)
      {
          return 0;
      }
      for(int i=0;i<z;i++)
      {
          //cout<<s1[i]<<" "<<s2[i]<<endl;
          //return true;
          if(mp.find(s1[i])==mp.end())
          {
              if(mp1.find(s2[i])!=mp1.end())
              {
                  return false;
              }
              mp[s1[i]]=s2[i];
              mp1[s2[i]]=1;
              //mp[s2[i]]=s1[i];
          }
          else{
              if(mp[s1[i]]==s2[i])
              {
                  
              }
              else{
                  return false;
              }
          }
      }
      return true;
  }
};
