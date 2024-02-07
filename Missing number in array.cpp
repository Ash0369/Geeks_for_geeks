class Solution{
  public:
    int missingNumber(vector<int>& array, int n) 
    {
        int xr=1;
        
        for(int i=2;i<=n;i++)
        {
            xr=(xr^i);
        }
        
        for(auto x:array)
        {
            xr=xr^x;
        }
        return xr;
    }
};
