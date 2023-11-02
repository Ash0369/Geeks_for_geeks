class Solution{
  public:
    int minDist(int a[], int n, int x, int y) 
    {
        int ans=1e6;
        int a1=-1;
        int b1=-1;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==x)
            {
                a1=i;
            }
            if(a[i]==y)
            {
                b1=i;
            }
            if(a1>=0 && b1>=0)
            {
                ans=min(ans,abs(a1-b1));
            }
            
        }
        if(a1==-1 || b1==-1)
        {
            return -1;
        }
        return ans;
    }
};
