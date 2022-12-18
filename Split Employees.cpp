class Solution 
{
  public:
    int splitEmployees(int n, string s[]) 
    {
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i][0]]++;
        }
        int uf=0;
        for(auto x:mp)
        {
            int ele=x.second;
            if(ele%2==0 && ele>2)
            {
                uf+=ele-1;
            }
            else if(ele%2!=0 && ele>1)
            {
                uf+=ele-1;
            }
        }
        return uf;
        
    }
};
