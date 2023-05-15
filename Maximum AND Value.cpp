class Solution
{
    public:
    // Function for finding maximum AND value.
    int maxAND (int arr[], int N)
    {
        int ans=0;
        int n=N;
        for(int i=31;i>=0;i--)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                int ele=(arr[j]&(1<<i));
                if(ele!=0 && (arr[j]&ans)==ans)
                {
                    cnt++;
                }
            }
            if(cnt>=2)
            {
                ans+=(1<<i);
            }
        }
        return ans;
    }
};
