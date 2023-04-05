class Solution 
{
  public:
    int countSpecialNumbers(int N, vector<int> arr) 
    {
        int n=N;
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int ele=arr[i];
            if(i<n-1 && arr[i]==arr[i+1])
            {
                ans++;
                continue;
            }
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};
