#define ll long long
class Solution 
{
  public:
    int gameOfXor(int n, int vec[]) 
    {
        int xr=0;
        for(int i=0;i<n;i++)
        {
            ll int left=i;
            ll int right=n-i-1;
            ll int time=left*right;
            
            time+=left+right;
            time++;
            
            if(time%2)
            {
                xr=xr^vec[i];
            }
        }
        return xr;
    }
};
