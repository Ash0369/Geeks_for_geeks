class Solution 
{
  public:
    int minDist(int x1, int x2, int x3) {
        int d=(x1+x2+x3)/3;
        int ans=1e9;
        for(int j=max(0,d-5);j<=d+5;j++)
        {
            int t=abs(j-x1)+abs(j-x2)+abs(j-x3);
            ans=min(ans,t);
        }
        return ans;
    }
};
