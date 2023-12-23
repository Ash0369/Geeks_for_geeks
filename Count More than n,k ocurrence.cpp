class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) 
    {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int ans=0;
        for(auto x:mp)
        {
            if(x.second>(n/k))
            {
                ans++;
            }
        }
        return ans;
    }
};
