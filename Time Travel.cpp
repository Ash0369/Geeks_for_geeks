class Solution 
{
  public:
    int timeTravel(int n, vector<int> &arr) 
    {
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            {
                ans++;
            }
            if(arr[i]<arr[i-1])
            {
                ans+=2;
            }
        }
        return ans;
    }
};
