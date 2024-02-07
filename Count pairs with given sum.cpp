class Solution
{   
public:
    int getPairsCount(int arr[], int n, int k) 
    {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if((k-arr[i])==arr[i])
            {
                ans+=mp[k-arr[i]]-1;
                continue;
            }
            ans+=mp[k-arr[i]];
        }
        return ans/2;
    }
};
