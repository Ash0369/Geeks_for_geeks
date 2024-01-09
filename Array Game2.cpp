class Solution
{
    public:
    int min_operations(int n, vector<int>&arr, vector<int>&brr) 
    {
        int i=0;
        int j=0;
        
        
        int ans=0;
        while(j<n)
        {
            i=i%n;
            if(arr[i]==-1)
            {
                i++;
                continue;
            }
            if(arr[i]==brr[j])
            {
                arr[i]=-1;
                i++;
                j++;
                ans++;
            }
            else{
                ans++;
                i++;
            }
        }
        return ans;
    }
};
