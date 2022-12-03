#define ll long long
class Solution 
{
public:
    bool place(vector<int>&stalls,int mid,int k)
    {
        int n=stalls.size();
        ll int prev=stalls[0];
        k--;
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-prev>=mid)
            {
                prev=stalls[i];
                k--;
            }
        }
        
        if(k<=0)
        {
            return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) 
    {
        
        sort(stalls.begin(),stalls.end());
        ll int low=0;
        ll int high=stalls[n-1];
        ll int ans=stalls[n-1];
        
        while(low<=high)
        {
            ll int mid=(low+high)/2;
            if(place(stalls,mid,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return ans;
    }
};
