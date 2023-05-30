class Solution
{
public:
    int LargButMinFreq(int arr[], int n) 
    {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        int ans=0;
        int f=INT_MAX;
        for(auto x:mp)
        {
            if(x.second<=f)
            {
                f=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};
