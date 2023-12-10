class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        long long int s=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            mp[s]++;
        }
        for(auto x:mp)
        {
            if(x.first==0 || x.second==2)
            {
                return true;
            }
        }
        return false;
    }
};
