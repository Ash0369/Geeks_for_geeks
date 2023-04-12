class Solution
{
public:
    int dominantPairs(int n,vector<int> &arr)
    {
        sort(arr.begin(),arr.begin()+(n/2),greater<int>());
        sort(arr.begin()+(n/2),arr.end(),greater<int>());
        int i=0;
        int j=(n/2);
        int ans=0;
        while(i<(n/2) && j<n)
        {
            while(j<n && arr[i]<(5*arr[j]))
            {
                j++;
            }
            if(j<n)
            {
                ans=ans+(n)-j;
            }
            i++;
        }
        return ans;
    }  
};
