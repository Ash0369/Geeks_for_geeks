class Solution 
{
  public:
    int bitMagic(int n, vector<int> &arr) 
    {
        // code here
        int cnt=0;
        for(int i=0;i<(n/2);i++)
        {
            if(arr[i]!=arr[n-1-i])
            {
                cnt++;
            }
        }
        if(cnt%2==0)
        {
            return cnt/2;
        }
        
        return cnt/2+(1);
        
    }
};
